#include <Servo.h> 
Servo Myservo;
#define trigPin 11           // Trig Pin Of HC-SR04
#define echoPin 9        // Echo Pin Of HC-SR04
int speedpinA = 5;

#define MLa 4                   //left motor 1st pin
#define MLb 8                  //left motor 2nd pin
int mspeedA = 255;
// motor 2
int speedpinB = 3;
#define MRa 6               //right motor 1st pin
#define MRb 7               //right motor 2nd pin
int mspeedB =255;

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(speedpinA, OUTPUT);
  pinMode(MLa, OUTPUT);     // Set Motor Pins As O/P
  pinMode(MLb, OUTPUT);
  pinMode(speedpinB, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  Myservo.attach(10);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
  if (distance > 18)               // Condition For Absence Of Obstacle            
  {
    Myservo.write(90);
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, LOW);       // Move Forward
    digitalWrite(MRa, HIGH);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, HIGH);                                                       
  }
  else if ((distance <= 18)&&(distance > 0))            // Condition For Presence Of Obstacle
  {
    analogWrite(speedpinA, 0);
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 0);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);
    delay(100);
    Myservo.write(0);
    delay(1000);
    Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
if (distance > 18) 
{
    Myservo.write(90);
    delay(500);
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, HIGH);     // Move Backward             
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);
    delay(100);
   analogWrite(speedpinA, 0);
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 0);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);                             
    delay(500);  
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, LOW);     //RIGHT                
    digitalWrite(MRa, HIGH);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(900);
}
  else if ((distance <= 18)&&(distance > 0))
  {
   Myservo.write(180);
    delay(1000);
    Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
if (distance > 18)
{
    Myservo.write(90);
    delay(500);
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, HIGH);     // Move Backward              
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);
    delay(100);
    analogWrite(speedpinA, 0);
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 0);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);                             
    delay(500);  
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, LOW);     //LEFT               
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, HIGH);  
    delay(850);
   } 
  
    else if ((distance <=18)&&(distance > 0))
    {
    Myservo.write(90);
    delay(1000);
    analogWrite(speedpinA, 0);
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 0);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);                             
    delay(100);
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, HIGH);     // Move Backward             
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);
    delay(800);
    analogWrite(speedpinA, 0);
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    analogWrite(speedpinB, 0);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);                             
    delay(500); 
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, LOW);     //RIGHT               
    digitalWrite(MRa, HIGH);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(900);
    analogWrite(speedpinA, 255);
    digitalWrite(MRb, LOW);     //RIGHT              
    digitalWrite(MRa, HIGH);
    analogWrite(speedpinB, 185);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(900);
    }
  }
  }
}