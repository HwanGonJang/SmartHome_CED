#include <SoftwareSerial.h> // 시리얼 통신 라이브러리
#include <Servo.h> // 서보모터 제어 위함
#include "DHT.h" // 온습도센서 사용하기 위함(아두이노 내에서 별도 라이브러리 다운로드 받아야함)
#define no_dust 0.35 //미세먼지 센서 관련
#define DHTTYPE DHT11 // 온습도센서 관련
#define DHTPIN A0 //온습도센서 관련

//미세먼지, 온습도 조건문 관련 변수선언
int count = 0;
float vo_value = 0;
float sensor_voltage = 0;
float dust_density= 0;

//블루투스 핀 설정
int tx = 2;  //전송 핀 - 2번
int rx = 3;  //수송 핀 - 3번
SoftwareSerial btSerial(tx, rx);    //객체 선언

//초음파 핀 설정
int trig = 5;   //송신부 - 5번
int echo = 6;   //수신부 - 6번

//LED 핀 설정
int redLED = 7;    //위험 알림 불빛 - 7번

//모터 핀 설정
int door = 4;   //현관문 서보모터 - 6번
int angle = 90;    //모터의 각도 조절용
boolean front_a = false; 

int dustout = 8;
int window = 9;     //창문 서보모터 - 서윤하 servo2
int blind = 10;     //블라인드 서보모터 -김세연 servo3
int dhtPin = A0;
int dustIn = A1;
int light = A2;   // 김세연

Servo servo1;    //객체 선언 
Servo servo2;
Servo servo3;
DHT dht(DHTPIN, DHTTYPE);

//조도센서 관련 변수선언
int cdssValue = 0;
int cdssMax = 0;
int cdssMin = 1023;
int flag = 0;

char data;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  btSerial.begin(9600);
  servo1.attach(door);
  servo2.attach(window);
  servo3.attach(blind);
  
  //송신부-> OUTPUT , 수신부-> INPUT , 빨간불-> OUTPUT
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);
  
  //조도센서 calibration
  while(millis() < 5000) {
    cdssValue = analogRead(light);
    
    if(cdssValue > cdssMax) {
      cdssMax = cdssValue;
    }
    
    if(cdssValue < cdssMin) {
      cdssMin = cdssValue;
    }
  }
}

void loop()
{
  if(btSerial.available())
  {
    data = btSerial.read();
    Serial.print(data);
    Serial.print("\n");
  }
  vo_value = analogRead(dustout);
  sensor_voltage = get_voltage(vo_value);
  dust_density = get_dust_density(sensor_voltage);
  
  windowopen(dust_density);
  Serial.print("Dust Density : ");
  Serial.println(dust_density);
  windowopen_bluetooth(data);  
  
  if(data == 'g')
  {
    front_a = true;
    frontDoor_Open(front_a);
    front_a = false;
    frontDoor_Open(front_a);
    
  }  
  sonic_Secure();
  
  
  if(data == 'i')
  {
    bt_Blind(); 
  }
  delay(500);
  Blind();
}

void frontDoor_Open(boolean a)
{
  angle = 90;
   
  if(a)   //받은 값이 참(열림)이면...
  {
     angle = 60;
     servo1.write(angle);
     delay(100);
     angle = 90;
     servo1.write(angle);
     delay(5000);
     angle = 120;
     servo1.write(angle);
     delay(100);
     angle = 90;
     servo1.write(angle);
  }
  else
  {
    angle = 90;
    servo1.write(angle);
  }
  return;
}

void sonic_Secure(void)
{
  digitalWrite(trig, LOW);    //송신기를 LOW상태로 정렬
  digitalWrite(echo, LOW);    //수신기를 LOW상태로 정렬
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);   //초음파 송신
  delayMicroseconds(10);
  digitalWrite(trig, LOW);    //10마이크로초 동안 송신후 중단

  unsigned long duration = pulseIn(echo, HIGH);   //초음파가 갔다 오는데 걸린 시간 저장
  float distance = ((duration * 340) / 10000) / 2;   //단위 cm
  delay(500);

  if(distance >= 50)    //거리가 50cm 이상일때 위험 신호 X
  {
    digitalWrite(redLED, HIGH);
  }
  else if(distance < 50)    //거리가 20cm 이하일때 0.5초 간격으로 0.3초씩 유지
  {
    digitalWrite(redLED, HIGH);
    delay(100);
    digitalWrite(redLED, LOW);
    delay(1);
  }
  return;
}

void Blind(void) {
  cdssValue = analogRead(light);
  cdssValue = map(cdssValue, cdssMin, cdssMax, 0, 255);
  cdssValue = constrain(cdssValue, 0, 255);
  Serial.print(cdssValue);
  Serial.print("\n");
  
  //어두울 때 블라인드 올리기
  if(cdssValue > 150) {
    if(flag == 0) {
      servo3.write(45);
      delay(1000);
      servo3.write(92);
      flag = 1;
    }
  }
  
  // 밝을 때 블라인드 내리기
  if(cdssValue < 50) {
    if(flag == 1) {
      servo3.write(135);
      delay(1000);
      servo3.write(92);
      flag = 0;
    }
  }
}

void bt_Blind(void) {
  if(flag == 0) {
    servo3.write(45);
    delay(1000);
    servo3.write(92);
    flag = 1;
  }
  else if(flag == 1) {
    servo3.write(135);
    delay(1000);
    servo3.write(92);
    flag = 0;
  }
}

void windowopen(float dust_density)
{
  if(dust_density<50)
  {
    if(count == 0)
    {
      servo2.write(120);
      delay(180);
      servo2.write(90);
      count++;
    }
  }
  else
  {
    if(count == 1)
    {
      servo2.write(60);
      delay(180);
      servo2.write(90);
      count--;
    }
  }
}
float get_voltage(float value)
{
 // 아날로그 값을 전압 값으로 바꿈
 float V= value * 5.0 / 1024; 
 return V;
}

float get_dust_density(float voltage)
{
 // 데이터 시트에 있는 미세 먼지 농도(ug) 공식 기준
 float dust=(voltage-no_dust) / 0.05;
 return dust;
}


int windowopen_bluetooth(char data)
{
  if(data == 'h' && count == 0)
  {      
      servo2.write(120);
      delay(180);
      servo2.write(90);
      count++;
  }
  else if(data == 'h' && count == 1)
  {
      servo2.write(60);
      delay(180);
      servo2.write(90);
      count--;
  }
  else
  {
    
  }
