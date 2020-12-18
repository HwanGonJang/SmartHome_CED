#include "pitches.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial( 2,3);

const int ovenButton = 4 ;
const int ovenLed = 7 ;
const int dcMotor = 10 ;
const int speaker = 12 ; 
const int houseLed = 13;

boolean lastButton = LOW;
boolean currentButton = LOW;

int speed;

int note[] = {
  NOTE_A4,0,NOTE_A4,0,NOTE_A4
};

int times[] = {
  500,500,500,500,500
};

boolean ledOn = false;
boolean houseLedOn = false;

void setup() {
  pinMode(ovenButton, INPUT);
  pinMode(ovenLed, OUTPUT);
  pinMode (speaker, OUTPUT);
  pinMode (dcMotor, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  char data;
  data = mySerial.read();
  
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH){
    ledOn = true;   // 버튼이 눌리면 오븐의 전원이 켜지는 값으로 바뀜
  }
  
  lastButton = currentButton;

  if(data == 'a'){
    ledOn = true;
  }

  if (data == 'b'){
    houseLedOn = !houseLedOn;
    digitalWrite(houseLed,houseLedOn);
  }
  
  if(ledOn == true){
    speed = 15;
    digitalWrite(ovenLed,ledOn);
    analogWrite(dcMotor,speed);
    delay(5000);
    speed = 0;
    analogWrite(dcMotor,speed);
    ledOn = false;
    
    digitalWrite(ovenLed,ledOn);
    
    for(int i = 0 ; i < 5 ; i++){
      tone(speaker, note[i],times[i]);
      delay(times[i]);
    }
  }
}


boolean debounce(boolean last){
  boolean current = digitalRead(ovenButton);
  if (last != current){
    delay(5);
    current = digitalRead(ovenButton);
  }
  return current;
}
