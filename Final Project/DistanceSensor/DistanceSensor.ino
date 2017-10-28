int SensorPin = 0; //analog is the yellow cable
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(SensorPin);
  Serial.println(val);
  if(val>100){
    Serial.println("TOO CLOSE");
  }
  delay(1);
}
