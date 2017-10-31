#include <Servo.h>
#include <LiquidCrystal.h>

//Initialize LCD Display
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
Servo myServoL, myServoLT, myServoR, myServoRT; // Servo 1

float distValL, distValR, distValC;          // Read values of distance sensors.
float sLeft[5], sCenter[5], sRight[5];       // Array of distance values to average.
float avR, avC, avL;                         // Final distance value averages.
void setup() {
  lcd.begin(16, 2);
  lcd.print("Marshal Bot");                  // LCD Line 1 Name.
  myServoL.attach(11);                       //
  myServoLT.attach(10);                      //
  myServoR.attach(9);                        //
  myServoRT.attach(8);                       //
  pinMode(7, OUTPUT);
  lcd.setCursor(0, 1);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  MOTION(90, 90, 90, 90);                    // Opening position.
  delay(250);
  MOTION(45, 90, 135, 90);                   // Default position.
  delay(250);

}


void loop() {
  // Distance sensor data and calculations.

  for (int x = 0; x < 5; x++) {
    distValL = convertCM(analogRead(A0));
    sLeft[x] = distValL;
    distValC = convertCM(analogRead(A1));
    sCenter[x] = distValC;
    distValR = convertCM(analogRead(A2));
    sRight[x] = distValR;
    delay (10);
  }
  avL = sum(sLeft);
  avC = sum(sCenter);
  avR = sum(sRight);
  // Distance sensor serial print outs.
  Serial.print("Sum Left:");
  Serial.println(avL);
  Serial.print("Sum Center:");
  Serial.println(avC);
  Serial.print("Sum Right:");
  Serial.println(avR);
  delay(10);
  // IF Cases for movements.
  // CASE: Come Forward.
  if (avL >= 35 && avL <= 500 && avC >= 10 && avC <= 27 && avR >= 35 && avR <= 500) {
    LCD("Come Forward         ");
    MOTION(80, 0, 100, 160);
    delay(400);
    MOTION(100, 160, 80, 0);
    delay(400);
  }

  // CASE: Slow Down.
  if (avL >= 20 && avL < 50 && avC >= 8 && avC < 10 && avR >= 20 && avR < 50) {
    LCD("Slow Down            ");
    MOTION(90, 180, 90, 0);
    for (int pos1 = 0; pos1 <= 95; pos1 += 1) { // goes from 0 degrees to 180 degrees
      myServoRT.write(pos1);
      myServoLT.write((180 - pos1));
      delay(15);
    }
    delay(200);
  }

  // CASE: Stop.
  if (avL >= 20 && avL < 500 && avC >= 7 && avC < 8 && avR >= 20 && avR < 500) {
    LCD("Stop                 ");
    MOTION(100, 30, 80, 150);
    digitalWrite(7, HIGH);
    delay(400);
    digitalWrite(7, LOW);
  }

  // CASE: Turn Left Close.
  if (avL >= 10 && avL < 23 && avC >= 10 && avC <= 35 && avR >= 23 && avR <= 50 ) {
    LCD("Turn Right               ");
    MOTION(85, 180, 85, 180);
  }

  // CASE: Turn Right Close.
  if (avL >= 23 && avL <= 50 && avC >= 10 && avC <= 35 && avR >= 10 && avR < 23 ) {
    LCD("Turn Left               ");
    MOTION(105, 0, 105, 0);
  }
  /*
    // CASE: Turn Right.
    if (avL>= 35 &&avL<= 80 &&avC>= 10 &&avC<= 30 &&avR>= 20 &&avR<= 50){
    LCD("Turn Right");
    MOTION(135,180,135,180);
    delay(500);
    MOTION(80,75,130,180);
    delay(500);
    MOTION(135,180,135,180);
    delay(500);
    }
  */

}

// Conversion from distance sensor to CM.
float convertCM(float readValue) {
  return 12343.85 * pow(readValue, -1.15);
}

// 4 Servo Motor motion control.
void MOTION(int L, int LT, int R, int RT) {
  myServoL.write(L);
  myServoLT.write(LT);
  myServoR.write(R);
  myServoRT.write(RT);
}

// LCD Display.
void LCD(String S) {
  lcd.setCursor(0, 1);
  lcd.print(S);
}

// To get the mean.
float sum(float a[]) {
  float sum = 0;
  for (int x = 0; x < 5; x++) {
    sum += a[x];
  }
  return (sum / 5);
}

/*void sort(float a[],int n) {
   int i,j, temp;

   for(i=0;i<n-1;i++) {
      for(j=0;j<n-i-1;j++) {
         if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
  }
  // Mode
  float mode(float a[],int n) {
   float maxValue = 0;
   int maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      float count = 0;

      for (j = 0; j < n; ++j) {
         if (a[i]+2.5>=a[j]&& a[i]-2.5 <= a[j])
         ++count;
      }

      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }

   return maxValue;

   // Median
  void swap(float *p,float *q) {
   float t;

   t=*p;
    p=*q;
    q=t;
  }
  }*/

