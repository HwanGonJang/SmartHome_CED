//홈
#include <SoftwareSerial.h>               //라이브러리 선언
#include <LiquidCrystal_I2C.h>
int led = 4;            //거실 전등 led 변수 선언
int sw = 5;             //거실 전등 스위치 변수 선언
int led2 = 6;           //안방 전등 led 변수 선언
int sw2 = 7;            //안방 전등 스위치 변수 선언
int motor = 8;          //선풍기 변수
int a1 = 1;             //a1 ~ m1 각 기능 별 on/off를 위한 변수
int a2 = 1;
int t1 = 0;
int m1 = 1;


// 0x3F I2C 주소를 가지고 있는 16x2 LCD객체를 생성합니다.
LiquidCrystal_I2C lcd(0x27, 16, 2);       //tv용 i2c lcd 변수 선언 
SoftwareSerial mySerial(2, 3);            //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(led2, OUTPUT);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }
  
  mySerial.begin(9600);

  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
}

void loop() { 
  char data;                        //장갑으로 부터 데이터 받기
  data = mySerial.read();           

  tvFunc(data);
  light1Func(data);
  light2Func(data);
  fanFunc(data);
  
  Serial.println(data);
  delay(2000);
  
}

void tvFunc(char data) {          //tv on/off 함수
  if(data == 'b') {               //장갑으로 부터 b를 받으면 if문 실행
    t1 += 1;
  }

  if(t1 == 1) {
    lcd.clear();                   //lcd 초기화
    lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("5 SBS");
    lcd.setCursor(0,1);            // 0번째 줄 1번째 셀부터 입력하게 합니다.
    lcd.print("Running Man");
  } else if(t1 == 2) {
    lcd.clear();
    lcd.setCursor(0,0);            
    lcd.print("11 MBC");
    lcd.setCursor(0,1);            
    lcd.print("Muhan Dojeon");
  } else if(t1 == 3) {
    lcd.clear();
    lcd.setCursor(0,0);            
    lcd.print("Netflix");
    lcd.setCursor(0,1);            
    lcd.print("Friends ep.3");
  } else if(t1 == 0){
    lcd.clear();
    lcd.setCursor(0,0);            
    lcd.print("TV OFF");
  } 
  
  if(data == 'c') {                 //장갑으로 부터 c를 받으면 tv 종료
    lcd.clear();
    lcd.setCursor(0,0);            
    lcd.print("TV OFF");
    t1 = 0;
  }
}

void light1Func(char data) {       //거실 전등 함수
  if (digitalRead(sw) == LOW) {    //스위치 low면 음수 만들기
        a1 *= -1;
    }
    
  if (data == 'd'){                //장갑에서 d 받으면 음수 만들기 
           a1 *= -1;
  }
  if(a1 == -1) {                   //a1 변수 음수면 led 켜기 
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
}

void light2Func(char data) {      //안방 전등 함수(거실 전등과 동일)
  if (digitalRead(sw2) == LOW) {
     a2 *= -1;
    }
  
  if (data == 'e'){
     a2 *= -1;
  }
  if(a2 == -1) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}

void fanFunc(char data) {         //선풍기 함수(위와 동일)
  if(data == 'f') {
    m1 *= -1;
  }

  if(m1 == -1) {
      digitalWrite(motor, 1023);
    } else {
      digitalWrite(motor, LOW);
    }
}
