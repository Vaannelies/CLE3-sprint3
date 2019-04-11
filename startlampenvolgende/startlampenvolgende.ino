#include <Adafruit_NeoPixel.h>
 
#define PIN 10
#define LEDS 8

  int level = 0;
  int buttonpin = 13;
  bool lamp;
  bool lamp2;
  bool lamp3;
  int LDRValue = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 

{
  randomSeed(analogRead(A0));
Serial.begin(9600);
  for(int i = 0; i < 4; i++){
Serial.println("");
}
  
}

void loop() {

  
 if(analogRead(A15) > 950)
  {
  hinkelmodus();
   
  }
  
  if(analogRead(A15) < 950)
  {
    discomode();
  }
  LDRValue = analogRead(A15); //read the value from the LDR
  Serial.println(LDRValue);
  delay(1);

}

int hinkelmodus()
{
    
      strip.begin(); 
     if (level == 0) {
    strip.clear();
  strip.setPixelColor(7, 0, 255, 0); //Pixel 1 Red
  
  strip.setBrightness(100);//Pixel 3 blue
  strip.show(); //Shows the colors

 

      if (digitalRead(13) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 1;      
      }
       if ((digitalRead(3) == HIGH)  || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(12) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
         
      {
        error();
      }
  }
  
  if (level == 1) 
  {
    if(lamp == false)
    {
      for(int i = 0; i < 1; i++)
      {
      level1(); 
      }
    }
    lamp = true;
    
    if (strip.getPixelColor(6) != 0x000000)
    {
      Serial.println("2");
      if (digitalRead(2) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 2;
      }
      if ((digitalRead(3) == HIGH)  || 
          (digitalRead(13) == HIGH)  ||
          (digitalRead(12) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        error();
      }
    }
    
    if (strip.getPixelColor(1) != 0x000000)
    {
    Serial.println("3");
      if (digitalRead(3) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 2;
      }
      if ((digitalRead(6) == HIGH)  || 
          (digitalRead(12) == HIGH)  ||
          (digitalRead(13) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(2) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        error();
      }
    }
    
  }
  
  if (level == 2) 
  {
    if(lamp2 == false)
    {
      for(int i = 0; i < 1; i++)
      {
      level2(); 
      }
      
    }
    lamp2 = true;
    
    if (strip.getPixelColor(5) != 0x000000)
    {
      Serial.println("4");
      if (digitalRead(4) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 3;
      }
      if ((digitalRead(5) == HIGH)  || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(13) == HIGH)  ||
          (digitalRead(12) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        error();
      }
    }
    
    if (strip.getPixelColor(2) != 0x000000)
    {
    Serial.println("5");
      if (digitalRead(5) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 3;
      }
      if ((digitalRead(4) == HIGH)  || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(12) == HIGH)  ||
          (digitalRead(13) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        error();
      }
    }
    
  }
 if (level == 3) 
  
  {
    if(lamp3 == false)
    {
      for(int i = 0; i < 1; i++)
      {
      level3(); 
      }
    }
    lamp3 = true;
    
    if (strip.getPixelColor(4) != 0x000000)
    {
      Serial.println("6");
      if (digitalRead(6) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 4;
      }
      if ((digitalRead(7) == HIGH) || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(13) == HIGH)  ||
          (digitalRead(12) == HIGH)
         )
      {
        error();
      }
    }
    
    if (strip.getPixelColor(3) != 0x000000)
    {
    Serial.println("7");
      if (digitalRead(7) == HIGH)
      {
        strip.clear();
        delay(500);
        level = 4;
      }
      if ((digitalRead(6) == HIGH) || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(12) == HIGH)  ||
          (digitalRead(13) == HIGH)
         )
      {
        error();
      }
    }
    
  }

  
  if (level == 4)
  {
    Serial.println("Yay!");
    for(int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i,255,0,255);
      strip.show();
      delay(25);
    }
    delay(200);
    
   achieved();
    
  }
}


int error(){
  strip.setPixelColor(1,255,0,0);
  strip.setPixelColor(2,255,0,0);
  strip.setPixelColor(0,255,0,0);
  strip.setPixelColor(3,255,0,0);
   strip.setPixelColor(4,255,0,0);
  strip.setPixelColor(5,255,0,0);
  strip.setPixelColor(6,255,0,0);
  strip.setPixelColor(7,255,0,0);
  strip.show();
  delay(1000);
   lamp = false;
   lamp2 = false;
   lamp3 = false;
  level = 0;
}

int achieved(){
  lamp = false;
   lamp2 = false;
  lamp3 = false;
  level = 0;
}

  int level1(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(2,4);
    if(e == 2)
    {
  strip.setPixelColor(6, 0xFF0000); //Pixel 3 blue
    }
      if(e == 3)
    {
  strip.setPixelColor(1, 0xFF0000); //Pixel 3 blue
    }
    
  
  strip.setBrightness(50);//Pixel 3 blue
    strip.show(); //Shows the colors
  }

 int level2(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(4,6);
    if(e == 4)
    {
  strip.setPixelColor(5, 0xFFFF00); //Pixel 3 blue
    }
      if(e == 5)
    {
  strip.setPixelColor(2, 0xFF00FF); //Pixel 3 blue
    }
 
  strip.setBrightness(50);//Pixel 3 blue
    strip.show(); //Shows the colors
  }
   

 int level3(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(6,8);
  if(e == 6)
    {
  strip.setPixelColor(4, 0xF000FF); //Pixel 3 blue
    }
      if(e == 7)
    {
  strip.setPixelColor(3, 0x00FF00); //Pixel 3 blue
    }
  
  strip.setBrightness(50);//Pixel 3 blue
    strip.show(); //Shows the colors
  }

int discomode(){
  // Fill along the length of the strip in various colors...
  colorWipe(strip.Color(255,   0,   0)     , 50); // Red
  colorWipe(strip.Color(  0, 255,   0)     , 50); // Green
  colorWipe(strip.Color(  0,   0, 255)     , 50); // Blue
  colorWipe(strip.Color(  0,   0,   0, 255), 50); // True white (not RGB white)

  whiteOverRainbow(75, 5);

  pulseWhite(5);

  rainbowFade2White(3, 3, 1);
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(0);                           //  Pause for a moment
  }
}

void whiteOverRainbow(int whiteSpeed, int whiteLength) {

  if(whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;

  int      head          = whiteLength - 1;
  int      tail          = 0;
  int      loops         = 3;
  int      loopNum       = 0;
  uint32_t lastTime      = millis();
  uint32_t firstPixelHue = 0;

  for(;;) { // Repeat forever (or until a 'break' or 'return')
    for(int i=0; i<strip.numPixels(); i++) {  // For each pixel in strip...
      if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
         ((tail > head) && ((i >= tail) || (i <= head)))) {
        strip.setPixelColor(i, strip.Color(0, 0, 0, 255)); // Set white
      } else {                                             // else set rainbow
        int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
        strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
      }
    }

    strip.show(); // Update strip with new contents
    // There's no delay here, it just runs full-tilt until the timer and
    // counter combination below runs out.

    firstPixelHue += 40; // Advance just a little along the color wheel

    if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
      if(++head >= strip.numPixels()) {      // Advance head, wrap around
        head = 0;
        if(++loopNum >= loops) return;
      }
      if(++tail >= strip.numPixels()) {      // Advance tail, wrap around
        tail = 0;
      }
      lastTime = millis();                   // Save time of last movement
    }
  }
}

void pulseWhite(uint8_t wait) {
  for(int j=0; j<256; j++) { // Ramp up from 0 to 255
    // Fill entire strip with white at gamma-corrected brightness level 'j':
    strip.fill(strip.Color(0, 0, 0, strip.gamma8(j)));
    strip.show();
    delay(0);
  }

  for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
    strip.fill(strip.Color(0, 0, 0, strip.gamma8(j)));
    strip.show();
    delay(0);
  }
}

void rainbowFade2White(int wait, int rainbowLoops, int whiteLoops) {
  int fadeVal=0, fadeMax=100;

  // Hue of first pixel runs 'rainbowLoops' complete loops through the color
  // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to rainbowLoops*65536, using steps of 256 so we
  // advance around the wheel at a decent clip.
  for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
    firstPixelHue += 256) {

    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...

      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      uint32_t pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());

      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the three-argument variant, though the
      // second value (saturation) is a constant 255.
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue, 255,
        255 * fadeVal / fadeMax)));
    }

    strip.show();
    delay(1);

    if(firstPixelHue < 65536) {                              // First loop,
      if(fadeVal < fadeMax) fadeVal++;                       // fade in
    } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
      if(fadeVal > 0) fadeVal--;                             // fade out
    } else {
      fadeVal = fadeMax; // Interim loop, make sure fade is at max
    }
  }

  for(int k=0; k<whiteLoops; k++) {
    for(int j=0; j<256; j++) { // Ramp up 0 to 255
      // Fill entire strip with white at gamma-corrected brightness level 'j':
      strip.fill(strip.Color(0, 0, 0, strip.gamma8(j)));
      strip.show();
    }
    delay(1); // Pause 1 second
    for(int j=255; j>=0; j--) { // Ramp down 255 to 0
      strip.fill(strip.Color(0, 0, 0, strip.gamma8(j)));
      strip.show();
    }
  }

  delay(1); // Pause 1 second
}
