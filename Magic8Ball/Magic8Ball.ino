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
  //Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("MAGIC 8 BALL");
}

void loop() {
  // put your main code here, to run repeatedly:

  tiltStatus = digitalRead(buttonPin);
  //Compare the read buttonState to our previous state to detect change
    // If the state has changed, 
    if (tiltStatus == HIGH) {
      
      msgValue = random(4) ;
      lcd.setCursor(0,1);
      switch (msgValue){
      case 0: 
        lcd.print("No                      ");
        break;
      case 1: 
        lcd.print("Yes!                    ");
        break;
      case 2:
        lcd.print("Definitely              ");
        break;
      case 3:
        lcd.print("Never                   ");
        break; 
      case 4:
        lcd.print("Sometimes               ");
        break; 
      }
    }
   delay(250);

  
}
