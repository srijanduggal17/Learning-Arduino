#include <Servo.h> //includes the servo library
Servo cr; //names the servo

int pot = A0; //sets a variable called "pot" to be A0


void setup() {
  // put your setup code here, to run once:
  cr.attach(9); //connects the servo to data pin 9
  cr.write(1500); //sends a value of 1500 (neutral)
  pinMode (pot, INPUT); //designates that pin A0 is an input
  Serial.begin (9600); //designates serial communication speed
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int potread = analogRead(pot); //declares a variable "potread" to be the values coming from A0
 
    int value = map (potread, 0, 1023, 1300, 1700); //maps the values from A0 to the range of the servo into a variable called "value"
   Serial.println (value); //shows us the numbers for "value"

   
  if (value >=1490 && value <= 1550) //in case the potentiometer signal fluctuates
  {
    cr.write(1500); //neutral
    Serial.println ("neutral"); //the word "neutral" will show up on the serial monitor if value is between 1490 and 1550
  }
  
  else if (value <=1310) //in case the potentiometer signal fluctuates
  {
    cr.write(1300); //writes 100% in one direction
    Serial.println ("full reverse"); //the word "full reverse" will show up on the serial monitor if value is less than 1310
  }

  else if (value >= 1690) //in case the potentiometer signal fluctuates
  {
    cr.write(1700); //writes 100% in opposite direction
    Serial.println ("full forward"); //the word "full forward" will show up on the serial monitor if value is greater than 1690
  }

  else 
  {
    cr.write(value); //if the value is not close to 100% in either direction of neutral, it will output the actual value
  }

}


