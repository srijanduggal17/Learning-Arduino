int pot = A0; //potentiometer is on A0
#include <Servo.h> //include servo library
Servo myservo; //naming the servo

void setup() {
  // put your setup code here, to run once:

pinMode (pot, INPUT); //A0 is designated as an input
Serial.begin (9600); //rate of communication from pc to arduino is denoted
myservo.attach(10); //servo is attached to pin 10
myservo.write(90); //move servo to value of 90

}

void loop() {
  // put your main code here, to run repeatedly:
int potRead = analogRead(pot); //declare variable "potRead" to be the values from the potentiometer

Serial.println (potRead); //print the variable "potRead" to the serial monitor

int maps = map(potRead, 0, 1023, 0, 180); /*declare variable "maps" to be a value. This value will be from 0 to 180
                                            corresponding to the "potRead", which is from 0 to 1023*/

myservo.write(maps); //move servo to the value of "maps"
    
}
