/*
  LCD circuit:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * CLK to Digital 2
 * DAT to Digital 3
 * LAT to Digital 4
*/


// LCD libraries:
#include "Wire.h"
#include "LiquidCrystal.h"

// Connect via SPI. Data pin is #3, Clock is #2 and Latch is #4
LiquidCrystal lcd(0);


//radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN 9  
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe</p><p>/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
long message = 0;

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Powered on");
  delay(1000);
  lcd.clear();
  Serial.begin (115200);
  pinMode (7,INPUT);

  radio.begin();
  radio.openWritingPipe(pipe);
  
}

void loop() {

   int emergency = digitalRead(8);

  
  
  int throttle = map (analogRead (A1),0,1023,0,100);
  //Serial.print (throttle);

  int steering = map (analogRead (A0), 0,1023,0,180);
  //Serial.println(steering);

  int servospeed = map(analogRead (A1),0,1023,1300,1700);
  
  message = servospeed*1000L + steering;
  if(emergency == HIGH) {
    message = 1701181;  
  }
  radio.write(&message, sizeof(message));
  Serial.println(message);
  
  

   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  if (throttle <10)
    {
      lcd.print(throttle);
      lcd.print("  %");
    }

  else if (throttle <100)
    {
      lcd.print(throttle);
      lcd.print(" %");
    }

  else
    {
      lcd.print(throttle);
      lcd.print("%");
    }


  int dir = digitalRead(7);
  
  if (dir == HIGH)
    {
      lcd.print(" F");
    }

  else
    {
      lcd.print(" R");
    }
  
}

