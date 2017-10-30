#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
Servo myServoL,myServoLT,myServoR,myServoRT; // Servo 1

int pos1 = 0, pos2 = 0, pos3 = 0, pos4 =0;              // Servo motor positions.
float distValL, distValR, distValC;                     // Read values of distance sensors.
int SensorPin = 0;                                      // Analog Distance Sensor

void setup() {
  lcd.begin(16,2);
  lcd.print("Marshal Bot");                        // LCD Line 1 Name
  myServoL.attach(11);                             //
  myServoLT.attach(10);                            // 
  myServoR.attach(9);                              //   
  myServoRT.attach(8);                             // 
  lcd.setCursor(0,1);
  Serial.begin(9600);   
  pinMode(LED_BUILTIN, OUTPUT);
  MOTION(90,90,90,90); //90 bottom:180 left top:0 right top: is straight.
  delay(1000);
  MOTION(90,180,90,180);
  delay(1000);
}

void loop() {
  distValL = convertCM(analogRead(A0));
  distValC = convertCM(analogRead(A1));
  distValR = convertCM(analogRead(A2));
  delay(100);
  Serial.println(distValL);
  Serial.println(distValC);
  Serial.println(distValR);

  /*LCD("Testing Turn Right");
  MOTION(80,45,80,180);
  delay(500);
  MOTION(100,180,100,180);
  delay(500);*/
  
  LCD("Testing Come Forward");
  MOTION(180,0,0,180);
  delay(500);
  MOTION(180,135,0,45);
  delay(500);
   
  /*LCD("Testing Turn Left");
  MOTION(80,0,80,0);
  delay(500);
  MOTION(100,0,100,135);
  delay(500);*/

}

// Conversion from distance sensor to CM
float convertCM(float readValue){
  return 12343.85*pow(readValue,-1.15);
}
// 4 Servo Motor motion control
void MOTION(int L,int LT, int R, int RT){
  myServoL.write(L);
  myServoLT.write(LT);
  myServoR.write(R);
  myServoRT.write(RT);
}
// LCD Display
void LCD(String S) {
  lcd.setCursor(0,1);
  lcd.print(S);
}

