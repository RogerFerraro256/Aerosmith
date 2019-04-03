
#include <Arduino.h>
#include <Servo.h>.
 
const int trigPin = 2;
const int echoPin = 3;


long duration;
int dist;

Servo myServo; 

void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  myServo.attach(8); 

  Serial.begin(9600);
  
}

//this will calculate the distance and return value in CM (metric sistem rules!!)
int getDist()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist = duration * 0.034 / 2;
  return dist;
}

void writeOnSerial(int i){
  myServo.write(i);
  delay(30);
  dist = getDist();
    
  Serial.print(i);
  Serial.print(",");
  Serial.print(dist);
  Serial.print(".");
}

void loop()
{
  //in the loop this will only rotate the servo
  for (int i = 15; i <= 165; i++)
  {
    writeOnSerial(i);
  }
  for (int i = 165; i > 15; i--)
  {
    writeOnSerial(i);
  }
}


