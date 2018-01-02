int pot = A0;   //we are making a variable for the potentiometer pin, which will be A0 because want to read the values from the potentiometer 
#include <Servo.h>    // includes the library
Servo steering;   //naming the servo
int button = 13;    //The pin for the button will be 13
int lastReading = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode (pot, INPUT);   //the potentiometer should be an input since we will be taking values from it
  Serial.begin (9600);    //The rate at which the arduino communicates with the computer should be the same and needs to be declared
  steering.attach (11);   // we want to designate that the servo is hooked up to pin 11
  steering.write (90);    //we want to start the servo in the 90 degree position (centered)
  pinMode (button, INPUT);    //We want the button to be an input so that we can use the data to perform another task
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
 int potRead = analogRead (pot);   //We are declaring a new variable "potRead" for the analog values that we get from the potentiometer
  //Serial.println (potRead);   //We want to collect the values that come from the potentiometer
  int steeringOutput = map(potRead, 0, 1023, 0, 180);   //We are declaring a new variable "steeringOutput" and setting it to convert the potRead,
                                    
                                                             //which is from 0 to 1023, to a range that the servo can use, which is 0 to 180
  if (digitalRead (button) == HIGH) {
    //Serial.println ("button pressed");
    steering.write(90);
  }

  else if (Change() == false){
    Serial.println ("false");
    steering.write(90);
    }
  
 else if (Change() == true){
  Serial.println("true");
  steering.write(steeringOutput);   //We want the input for the servo to be the converted range
  }

  
  

}

boolean Change() {
  int potRead = analogRead (pot);   //We are declaring a new variable "potRead" for the analog values that we get from the potentiometer
  
  if(potRead != lastReading) {

    lastReading = potRead;
    return true;
  }
  return false;
}


