#include <Servo.h>
Servo myServoL,myServoLT,myServoR,myServoRT; 

void setup() {
  // put your setup code here, to run once:
  myServoL.attach(11);                             //
  myServoLT.attach(10);                            // 
  myServoR.attach(9);                              //   
  myServoRT.attach(8);                             // 
}

void loop() {
  // put your main code here, to run repeatedly:
  myServoL.write(90);
  myServoLT.write(90);
  myServoR.write(90);
  myServoRT.write(90);
  delay(1000);
  myServoL.write(0);
  myServoLT.write(0);
  myServoR.write(0);
  myServoRT.write(0);
  delay(1000);
  myServoL.write(90);
  myServoLT.write(90);
  myServoR.write(90);
  myServoRT.write(90);
  delay(1000);
  myServoL.write(180);
  myServoLT.write(180);
  myServoR.write(180);
  myServoRT.write(180);
  delay(1000);
}
