# SmartHome_CED
아두이노를 활용한 완성도 있는 IoT 스마트홈 구축

## 개요
창의적 공학 설계 프로젝트로 아두이노를 활용한 IoT스마트홈 구축.     
구부림센서를 활용한 웨어러블 장갑과 블루투스 모듈 6개로 제어 가능하게 구상.

## 프로젝트 과정
### 집 제작
트로텍 레이저 커터로 제작한 도면을 정교하게 절단.      
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567813-a3a49600-4125-11eb-838d-a48421136b35.jpg">     
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567801-9e474b80-4125-11eb-9d83-29007d091d30.jpg">     
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567809-a2736900-4125-11eb-86b5-e060928ab17c.jpg">      
### 3D프린터 가구 제작
Fusion360 프로그램으로 모델링 후 3D모델 출력.      
=> 선풍기, 소파, TV케이스, 오븐, CED SmartHome 텍스트 모델링.     
#### 오븐 모델링
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567776-94254d00-4125-11eb-93c7-27b6f64eeaaf.jpg">      

#### 3D 프린팅
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567783-95567a00-4125-11eb-9ff0-b241fd2a7c3f.jpg">

### 기능
#### 웨어러블 장갑  
구부림 센서, LCD패널과 블루투스 모듈 3개로 스마트홈과 통신.     
<img width="400" src="https://user-images.githubusercontent.com/33739448/102569897-a3a69500-4129-11eb-88ec-351074a934fc.jpg">     

#### 오븐
부저, dc모터, LED로 버튼과 웨어러블 장갑에서 작동되는 오븐 제작
(oven.ino)     
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567826-abfcd100-4125-11eb-80c7-abfb53bef7c6.jpg">

#### 창문, 블라인드, 방범 문
1. 창문: 미세먼지 센서로 미세먼지가 많을때에는 자동으로 창문이 닫히고 또한 웨어러블 장갑을 제어하는 창문제작.
2. 블라인드: 조도 센서로 빛이 강할 때는 자동으로 내려오고 반대의 경우 올라가는 기능. 장갑으로 제어 가능.
3. 방범 문: 초음파 센서로 누군가 다가오면 LED불빛이 깜빡이며 경고표시. 장갑으로 제어 가능.
(window_blind_door.ino)     
##### 창문, 블라인드
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567835-aef7c180-4125-11eb-93fd-11d94afa8999.jpg">      

##### 방범 문
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567839-b028ee80-4125-11eb-8c1f-34043044b26a.jpg">

#### 조명, TV, 선풍기
1. 조명: 스위치와 장갑으로 제어하는 조명 2개.
2. TV: 장갑으로 제어하는 TV. 원하는 채널, 전원 ON/OFF기능.
3. 선풍기: 장갑으로 제어하는 선풍기.
(light_tv_fan.ino)     
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567848-b5863900-4125-11eb-9e4a-5c75f1d95c8c.jpg">

## 완성
<img width="400" src="https://user-images.githubusercontent.com/33739448/102567858-b919c000-4125-11eb-92d4-f58e38bfc05f.jpg">

#### 함께 열심히 참여해주신 창의적공학설계 나반 3조 CED 김민, 최녕환, 서윤하, 김세연 학우 분께 감사드립니다.




