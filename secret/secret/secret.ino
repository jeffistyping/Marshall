#include <Servo.h>
Servo myServoL, myServoLT, myServoR, myServoRT; // Servo 1
int functionSEL = 0;

void setup() {
  // put your setup code here, to run once:
  myServoL.attach(11);                       //
  myServoLT.attach(10);                      //
  myServoR.attach(9);                        //
  myServoRT.attach(8);                       //
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    functionSEL = Serial.read();
    if (functionSEL == 1) {
      dance();
      Serial.write(functionSEL);
    }
    if (functionSEL == 2) {
      demo();
    }
  }
}

void MOTION(int L, int LT, int R, int RT) {
  myServoL.write(L);
  myServoLT.write(LT);
  myServoR.write(R);
  myServoRT.write(RT);
}

void dance() {
  MOTION(90, 90, 90, 90);
  delay(250);
  MOTION(80, 0, 100, 160);
  delay(400);
  MOTION(100, 160, 80, 0);
  delay(400);
}

void demo() {
  MOTION(0, 0, 0, 0);
  delay(400);
  MOTION(180, 180, 180, 180);
  delay(400);
}

