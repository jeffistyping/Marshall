#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
Servo myServoL,myServoLT,myServoR,myServoRT; // Servo 1

int pos1 = 0, pos2 = 0, pos3 = 0, pos4 =0;              // Servo motor positions.
float distValL, distValR, distValC;                     // Read values of distance sensors.
int SensorPin = 0;                                      // Analog Distance Sensor

void setup() {
  myServoL.attach(11);                             //
  myServoLT.attach(10);                            // 
  myServoR.attach(9);                              //   
  myServoRT.attach(8);                             // 
  lcd.print("Marshal Bot");                        // LCD Line 1 Name
  lcd.setCursor(0,1);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  distValL = convertCM(analogRead(A0));
  distValC = convertCM(analogRead(A1));
  distValR = convertCM(analogRead(A2));
  delay(100);
  Serial.println(distValL);
  Serial.println(distValC);
  Serial.println(distValR);
  //lcd.print(valToCm);
  //lcd.print("  cm                ");   
        if (distValL>= 00 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Face Me"
          LCD("Face me             ");
          MOTION(0,0,0,0);
    }         
        if (distValL>= 10 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Turn Left"
          LCD("Turn left           ");
          MOTION(0,0,0,0);
    }          
        if (distValL>= 10 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Turn Right"
          LCD("Turn right          ");
          MOTION(0,0,0,0);
    }              
        if (distValL>= 10 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Slow Down"
          LCD("Slow down           ");
          MOTION(0,0,0,0);
    }                
        if (distValL>= 10 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Proceed Forward"
          LCD("Proceed Forward     ");
          MOTION(0,0,0,0);
    }          
        if (distValL>= 10 &&distValL<= 12 &&distValC>= 10 &&distValC<= 12 &&distValR>= 10 &&distValR<= 12){
      // CASE  "Stop"
          LCD("Stop                ");
          MOTION(0,0,0,0);
    }                 
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

