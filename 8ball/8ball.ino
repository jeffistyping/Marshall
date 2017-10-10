#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


int tiltStatus = 0; // 0 = off, 1 = on
int lastTiltStatus = 0; // read value from pin
int msgValue = 0;

const int buttonPin = 7;
const int ledPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltStatus = digitalRead(buttonPin);
  //Compare the read buttonState to our previous state to detect change
  if (tiltStatus != lastTiltStatus) {
    // If the state has changed, 
    if (tiltStatus == HIGH) {
      msgValue =  random(1,10);
      switch (msgValue){
      case '1': 
        lcd.print("msg 1");
        break;
      case '2': 
        lcd.print("msg 2");
        break;
      case '3': 
        lcd.print("msg 3");
        break; 
      case '4': 
        lcd.print("msg 4");
        break; 
      case '5': 
        lcd.print("msg 5");
        break; 
      case '6': 
        lcd.print("msg 6");
        break;
      case '7': 
        lcd.print("msg 7");
        break;
      case '8': 
        lcd.print("msg 8");
        break;
      case '9': 
        lcd.print("msg 9");
        break;
      case 10:  
        lcd.print("msg 10");
        break;
      }
    }
    delay(50);
  }
  
}
