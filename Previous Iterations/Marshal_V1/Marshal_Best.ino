#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
Servo myServoL,myServoLT,myServoR,myServoRT; // Servo 1

int pos1 = 0, pos2 = 0, pos3 = 0, pos4 =0;              // Servo motor positions.
float distValL, distValR, distValC;                     // Read values of distance sensors.
int SensorPin = 0;                                      // Analog Distance Sensor
float sLeft[5],sCenter[5],sRight[5];
float avR,avC,avL;

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
  MOTION(90,180,90,0);
  delay(1000);
}

void loop() {
  for (int x=0; x<5; x++){
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
  Serial.print("Sum Left:");
  Serial.println(avL);
  Serial.print("Sum Center:");
  Serial.println(avC);
  Serial.print("Sum Right:");
  Serial.println(avR);
  delay(10);

 /* for (int x=0; x<10; x++){
  distValC = convertCM(analogRead(A1));
  sCenter[x] = distValC;
  delay (100);
  }
  avC = sum(sCenter);
  Serial.print("Sum Center:");
  Serial.println(avC);
  delay(50);

  for (int x=0; x<10; x++){
  distValR = convertCM(analogRead(A2));
  sRight[x] = distValR;
  delay(100);
  }
  avR = sum(sRight);
  Serial.print("Sum Right:");
  Serial.println(avR);
  delay(50);*/

  if (avL>= 7 &&avL<= 20 &&avC>= 7 &&avC<= 20 &&avR>= 7 &&avR<= 20){
  LCD("Testing Come Forward");
  MOTION(90,180,90,0);
  delay(500);
  MOTION(90,0,90,180);
  delay(500);
  }
  
  /*if (avL>= 7 &&avL<= 20 &&avC>= 7 &&avC<= 20 &&avR>= 7 &&avR<= 20)
  MOTION(80,45,80,180);
  delay(500);
  MOTION(100,180,100,180);
  delay(500);
  
  LCD("Testing Come Forward");
  MOTION(180,0,0,180);
  delay(500);
  MOTION(180,135,0,45);
  delay(500);
   
  LCD("Testing Turn Left");
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
// Median
void swap(float *p,float *q) {
   float t;
   
   t=*p; 
   *p=*q; 
   *q=t;
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
}*/
float sum(float a[]) {
      float sum = 0;
    for (int x=0; x<5; x++){
    sum+=a[x];
    }
  return (sum/5);
}


