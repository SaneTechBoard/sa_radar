
#include <Servo.h>. 
const int trigPin = 10;
const int echoPin = 11;
const int l1 = 4;
const int l2 = 8;
const int b = 5;
long duration;
int distance;
Servo servo; 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
  servo.attach(12); 
}
void loop() {
  for(int i=15;i<=165;i++){  
  servo.write(i);
  delay(30);
  distance = calculateDistance();
  if (distance < 100)
  {
    digitalWrite(l1, HIGH);
  }
  else
  {
    digitalWrite(l1, LOW);
  }
  Serial.println(i);
  delay(1);
  if (distance < 10)
  {
    digitalWrite(l2, HIGH);
    digitalWrite(b, HIGH);
  }
  else 
  {
    digitalWrite(l2, LOW);
    digitalWrite(b, LOW);
  }
  Serial.println(i);
  delay(1); 
  //Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }
  
  for(int i=165;i>15;i--){  
  servo.write(i);
  delay(30);
  distance = calculateDistance();
  if (distance < 100)
  {
    digitalWrite(l1, HIGH);
  }
  else
  {
    digitalWrite(l1, LOW);
  }
  Serial.println(i);
  delay(1);
  if (distance < 10)
  {
    digitalWrite(l2, HIGH);
    digitalWrite(b, HIGH);
  }
  else 
  {
    digitalWrite(l2, LOW);
    digitalWrite(b, LOW);
  }
  Serial.println(i);
  delay(1);
  //Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
