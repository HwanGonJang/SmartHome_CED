# SmartHome_CED
아두이노를 활용한 완성도 있는 IoT 스마트홈 구축

## 개요
창의적 공학 설계 강의의 프로젝트로 아두이노를 활용한 IoT스마트홈을 구축했습니다. 구부림센서를 활용한 웨어러블 장갑과 블루투스 모듈 6개로 수 많은 기능을 제어할 수 있도록 구현하였습니다.

## 개발과정
창의적 공학 설계 강의는 아두이노 이론을 배우고 직접 코딩하여 팀 프로젝트로 하나의 결과물을 만드는 강의입니다. 저는 첫 소프트웨어 공부를 고1 아두이노로 시작했기 때문에 자신있었습니다. 

#### 개발 기술
* Arduino
  * 개발을 위한 보드입니다. 아두이노 코딩은 기본적으로 C++을 기반으로 합니다.



### 1. 집 제작
일러스트로 제작한 도면을 레이저커터로 정교하게 절단합니다.  
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_4.jpg?raw=true'>
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_5.jpg?raw=true'>
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_3.jpg?raw=true'>

### 2. 3D프린터 가구 제작
팅커캐드, Fusion360 프로그램으로 모델링 후 3D모델을 출력합니다.
=> 선풍기, 소파, TV케이스, 오븐, CED SmartHome 텍스트 모델링.    
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_1.jpg?raw=true'>

<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_2.jpg?raw=true'>


### 3. 기능 구현
#### 웨어러블 장갑  
구부림 센서, LCD패널과 블루투스 모듈 3개로 스마트홈과 통신합니다.  
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_11.jpg?raw=true'>  

#### 오븐
부저, dc모터, LED로 버튼과 웨어러블 장갑에서 작동되는 오븐입니다.
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_8.jpg?raw=true'>

#### 창문, 블라인드, 방범 문
1. 창문: 미세먼지 센서로 미세먼지가 많을때에는 자동으로 창문이 닫히고 또한 웨어러블 장갑으로 제어하는 창문입니다.
2. 블라인드: 조도 센서로 빛이 강할 때는 자동으로 내려오고 반대의 경우 올라가는 기능. 장갑으로 제어할 수 있습니다.
3. 방범 문: 초음파 센서로 누군가 다가오면 LED불빛이 깜빡이며 경고표시. 장갑으로 제어 가능합니다.

<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_6.jpg?raw=true'>    

<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_7.jpg?raw=true'>


#### 조명, TV, 선풍기
1. 조명: 스위치와 장갑으로 제어하는 조명 2개.
2. TV: 장갑으로 제어하는 TV. 원하는 채널, 전원 ON/OFF기능.
3. 선풍기: 장갑으로 제어하는 선풍기.
   

<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_10.jpg?raw=true'>

## 결과
<img src='https://github.com/HwanGonJang/HwanGonJang.github.io/blob/master/Pictures/ah_9.jpg?raw=true'>

이렇게 웨어러블 장갑으로 제어하는  IoT 스마트홈을 구축하였습니다. 한 학기 동안 팀으로써 개발을 할 수 있어서 즐거웠습니다. 

다음은 시연 영상입니다.

https://youtu.be/UuohBvx4NSs




#### 함께 열심히 참여해주신 창의적공학설계 나반 3조 CED 김민, 최녕환, 서윤하, 김세연 님께 감사드립니다.



