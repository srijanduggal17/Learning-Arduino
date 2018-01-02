#include <Servo.h>

Servo myServo;

void setup() { 
  myServo.attach(6);
  myServo.writeMicroseconds(1500);  // Stop
} 

void loop() { }
