//servo
#include <Servo.h>
Servo cr;
Servo myservo;

//radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN 9
#define CSN_PIN 10 // NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe</p><p>/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio</p><p>/*-----( Declare Variables )-----*/
long base = 0;


void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
  cr.attach(6);
  cr.write(1500);
  myservo.attach(5);
  myservo.write(90);

  delay(5000);

}



void loop() {
    if (radio.available()){
      // Dump the payloads until we've gotten everything
      unsigned long got_time;
      bool done = false;

      // Fetch the payload, and see if this was the last one.
      done = radio.read( &got_time, sizeof(unsigned long) );

     base = got_time;
      // Serial.print(base);
     
      delay(20);

    }

     if (base == 1701181)
    {
      cr.write (1500);
      myservo.write (90);
      endProgram();
    }
    
     Serial.print("Base:\t");
     Serial.print(base);

    int servospeed = base / 1000L;
    Serial.print ("  Servo Speed:\t");
    Serial.print (servospeed);

    
    int steering = base - (servospeed*1000L);
    Serial.print ("  Steering:\t");
    Serial.println (steering);

    

    cr.write(servospeed);
    myservo.write(steering);
    
}

void endProgram()
{
  while (true)
  {
    digitalWrite (8, HIGH);
  }
}


