#include <Servo.h>
#include <Wire.h>

Servo myServoL,myServoLT,myServoR,myServoRT; // Servo 1
int x = 0;
void setup() {
  Wire.begin(8); //joing i2c bus with address 1
  Wire.onReceive(recieveEvent); //register event 
  Serial.begin(9600);
  // put your setup code here, to run once:
  myServoL.attach(11);                             //
  myServoLT.attach(10);                            // 
  myServoR.attach(9);                              //   
  myServoRT.attach(8);                             // 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  }
void recieveEvent(int howMany){
  int x = Wire.read();
  Serial.println(x);
  switch (x) {
    case 1:
      MOTION(80,45,80,180);
      delay(500);
      MOTION(100,180,100,180);
      delay(500);
      break;
    case 2:
      MOTION(180,0,0,180);
      delay(500);
      MOTION(180,135,0,45);
      delay(500);
      break;
    case 3:
      MOTION(80,0,80,0);
      delay(500);
      MOTION(100,0,100,135);
      delay(500);
      break;   
  }
}
  
// 4 Servo Motor motion control
void MOTION(int L,int LT, int R, int RT){
  myServoL.write(L);
  myServoLT.write(LT);
  myServoR.write(R);
  myServoRT.write(RT);
}
