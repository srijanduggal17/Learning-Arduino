#include <Adafruit_NeoPixel.h>
      #define PIN 11

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int i=0;
int val = 500;

void setup() {
  Serial.begin(9600); 
  strip.begin();
  strip.show(); //initialize all pixels to off

}


void loop() {
  int force = analogRead(A4);
  Serial.println(force);
  
  if(force > val) {
    if (i==0) { 
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }


    else if (i==1) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }


    else if (i==2) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }


    else if (i==3) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    
    else if (i==4) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
        }
      strip.show();
      delay(500);
      i = i+1;
    }



    else if (i==5) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }
  
    else if (i==6) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(255, 255, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }


    else if (i==7) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    else if (i==8) {
     for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 255));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    else if (i==9) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }
    
    else if (i==10) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 255));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    else if (i==11) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    else if (i==12) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(255, 255, 255));
        }
      strip.show();
      delay(500);
      i = i+1;
    }

    else if (i==13) {
      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
      strip.show();
      delay(500);
      i = 0;
    }

  }
  }


