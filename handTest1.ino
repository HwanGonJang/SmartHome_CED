//장갑
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
int flexpin1 = A3;  //구부림센서 값을 센싱할 아날로그 핀을 지정합니다.
int flexpin2 = A2;
int flexpin3 = A1; 
int flexpin4 = A0;

// 0x3F I2C 주소를 가지고 있는 16x2 LCD객체를 생성합니다.
LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
SoftwareSerial mySerial2(6, 7);
SoftwareSerial mySerial3(8, 9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }
  mySerial.begin(9600);
  mySerial2.begin(9600);
  mySerial3.begin(9600);
  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
}

void loop() {
  //센서값을 저장할 변수 설정합니다.
  int flexVal1; 
  int flexVal2; 
  int flexVal3; 
  int flexVal4; 
  char data;              //블루투스 통신으로 보낼 데이터 변수 선언
  
  // 센서로 부터 보내오는 값을 입력 받습니다.(0-1023)
  flexVal1 = analogRead(flexpin1); 
  flexVal2 = analogRead(flexpin2); 
  flexVal3 = analogRead(flexpin3); 
  flexVal4 = analogRead(flexpin4); 
  
 
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }           //전자레인지 아두이노로 데이터 보내기

  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial2.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }           //문, 창문 아두이노로 보내기

  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial3.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }           //전등, tv, 선풍기 아두이노로 보내기
  
  // sensor:XXX 로 출력한다(XXX값은 센서로 부터 읽어 온 값)
  Serial.print("     sensor: ");
  Serial.print(flexVal1); 
  Serial.print("     sensor: ");
  Serial.print(flexVal2);
  Serial.print("     sensor: ");
  Serial.print(flexVal3);
  Serial.print("     sensor: ");
  Serial.println(flexVal4);

  data = handVal(data, flexVal1, flexVal2, flexVal3, flexVal4);
  Serial.println(data);
  mySerial.write(data);
  mySerial2.write(data);
  mySerial3.write(data);

  if(data == 'a') {                 //전자레인지 딜레이 조건문
    delay(5000);
    lcd.setCursor(0,0);            
    lcd.print("MicroWave Off");
  }

  delay(2000);
  lcd.clear();
}

char handVal(char _data, int _flexVal1, int _flexVal2, int _flexVal3, int _flexVal4) {
  if(_flexVal1 < 100 && _flexVal2 < 100 && _flexVal3 < 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Waiting...");
    _data = 'z';        //대기 상태
  } else if(_flexVal1 > 100 && _flexVal2 < 100 && _flexVal3 < 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("MicroWave On...");
    _data = 'a';        //전자레인지
  } else if(_flexVal1 < 100 && _flexVal2 > 100 && _flexVal3 < 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("TV on");
    _data = 'b';        //tv on
  } else if(_flexVal1 < 100 && _flexVal2 < 100 && _flexVal3 > 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("TV off");
    _data = 'c';        //tv off
  } else if(_flexVal1 < 100 && _flexVal2 < 100 && _flexVal3 < 100 && _flexVal4 > 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Room1 ON");
    _data = 'd';        //거실 전등
  } else if(_flexVal1 > 100 && _flexVal2 > 100 && _flexVal3 < 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Room2 ON");
    _data = 'e';        //안방 전등
  } else if(_flexVal1 > 100 && _flexVal2 > 100 && _flexVal3 > 100 && _flexVal4 > 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Fan ON");
    _data = 'f';        //선풍기
  } else if(_flexVal1 > 100 && _flexVal2 < 100 && _flexVal3 < 100 && _flexVal4 > 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Door Open");
    _data = 'g';       //
  } else if(_flexVal1 < 100 && _flexVal2 > 100 && _flexVal3 > 100 && _flexVal4 < 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Window Open");
    _data = 'h';       //
  } else if(_flexVal1 < 100 && _flexVal2 < 100 && _flexVal3 > 100 && _flexVal4 > 100) {
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("Blind");
    _data = 'i';       //
  }

  return _data;
}
