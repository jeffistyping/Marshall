#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);

int x = 0;
int pos1 = 0, pos2 = 0, pos3 = 0, pos4 =0;              // Servo motor positions.
float distValL, distValR, distValC;                     // Read values of distance sensors.
int SensorPin = 0;                                      // Analog Distance Sensor

void setup() {
  lcd.begin(16,2);
  Wire.begin();
  lcd.print("Marshal Bot");                        // LCD Line 1 Name
  
  lcd.setCursor(0,1);
  Serial.begin(9600);   
  pinMode(LED_BUILTIN, OUTPUT);
  //MOTION(90,90,90,90); //90 bottom:180 left top:0 right top: is straight.
  //delay(1000);
  //MOTION(90,180,90,180);
  //delay(1000);
}

void loop() {
  distValL = convertCM(analogRead(A0));
  distValC = convertCM(analogRead(A1));
  distValR = convertCM(analogRead(A2));
  delay(2000);
  Serial.print("Left:");
  Serial.println(distValL);
  Serial.print("Center:");
  Serial.println(distValC);
  Serial.print("Right:");
  Serial.println(distValR);
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  if(x<=2){
    x++;}
  else if (x>=3){
    x=1;}
}

// Conversion from distance sensor to CM
float convertCM(float readValue){
  return 12343.85*pow(readValue,-1.15);
}
  
// LCD Display
void LCD(String S) {
  lcd.setCursor(0,1);
  lcd.print(S);
}

