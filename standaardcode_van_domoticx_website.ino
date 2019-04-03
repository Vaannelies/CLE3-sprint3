#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LEDS 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.show();  //Zet hier alle pixels op uit.
  pinMode(7, INPUT);
    strip.setPixelColor(1, 0, 0, 0); //Pixel 2 GROEN
 
}
 
void loop() {


  if (digitalRead(7) == LOW) {
     strip.setPixelColor(0, 0, 0, 0); //Pixel 1 ROOD
  strip.setPixelColor(1, 255, 0, 220); //Pixel 2 GROEN
  strip.setPixelColor(2, 0, 0, 0); //Pixel 3 BLAUW
   strip.setPixelColor(3, 0, 0, 200); //Pixel 3 BLAUW
  strip.show(); //Laat de kleuren zien!

  }

   if (digitalRead(7) == HIGH) {
     strip.setPixelColor(0, 0, 0, 0); //Pixel 1 ROOD
  strip.setPixelColor(1, 0, 0, 0); //Pixel 2 GROEN
  strip.setPixelColor(2, 0, 0, 0); //Pixel 3 BLAUW
   strip.setPixelColor(3, 255, 0, 0); //Pixel 3 BLAUW
  strip.show(); //Laat de kleuren zien!

  }
}
