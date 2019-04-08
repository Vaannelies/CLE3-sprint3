#include <Adafruit_NeoPixel.h>
 
#define PIN 10
#define LEDS 8

  int level = 0;
  int buttonpin = 13;
  bool lamp;
  bool lamp2;
  bool lamp3;

  
  String knop0 = "inactive"; //lampen 0 t/m 15. Lamp 1 is dus de middelste van de 3 lampen op de eerste rij. Lamp 0 is de eerste.
  String knop1 = "inactive"; //lampen 0 t/m 15. Lamp 1 is dus de middelste van de 3 lampen op de eerste rij. Lamp 0 is de eerste.
  String knop2 = "inactive"; //lampen 0 t/m 15. Lamp 1 is dus de middelste van de 3 lampen op de eerste rij. Lamp 0 is de eerste.
  String knop3 = "inactive"; //lampen 0 t/m 15. Lamp 1 is dus de middelste van de 3 lampen op de eerste rij. Lamp 0 is de eerste.

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

int fout(){
  strip.setPixelColor(1,0,0,200);
  strip.setPixelColor(2,0,0,200);
  strip.setPixelColor(0,0,0,200);
  strip.setPixelColor(3,0,0,200);
  strip.show();
  delay(200);
  bool lamp = false;
  bool lamp2 = false;
  bool lamp3 = false;
  level = 0;
}

int gehaald(){
  bool lamp = false;
  bool lamp2 = false;
  bool lamp3 = false;
  level = 0;
}

  int level1(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(2,4);
  strip.setPixelColor(e, 0xFF0000); //Pixel 3 BLAUW
  
  strip.setBrightness(50);//Pixel 3 BLAUW
    strip.show(); //Laat de kleuren zien!
    
    
    
  }

 int level2(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(4,6);
  strip.setPixelColor(e, 0xFF0000); //Pixel 3 BLAUW
  
  strip.setBrightness(50);//Pixel 3 BLAUW
    strip.show(); //Laat de kleuren zien!
    
    
    
  }
   

 int level3(){  
 strip.setPixelColor(1,0,0,0);
    int e = random(6,8);
  strip.setPixelColor(e, 0xFF0000); //Pixel 3 BLAUW
  
  strip.setBrightness(50);//Pixel 3 BLAUW
    strip.show(); //Laat de kleuren zien!
    
    
    
  }
   


void setup() {
  randomSeed(analogRead(A0));
Serial.begin(9600);
  for(int i = 0; i < 4; i++){
Serial.println("");
}
}
  

 
void loop() {
//als level 0 is, laat de middelste lamp branden en markeer die als 'active led'.
//als de active led wordt geselecteerd, ga je naar volgende level.
//als level 1 is, laat een willekeurige lamp branden van de 3 lampen op die rij. markeer die brandende lamp als active led.
//als de active led wordt geselecteerd, ga naar volgende level en laat steeds random lamp branden op volgende rij

//als je een andere lamp selecteert, ga je terug naar level 0

    
  
  
  
  
  
  
  
  
  
     if (level == 0) {
    strip.clear();
  strip.setPixelColor(0, 255, 0, 0); //Pixel 1 ROOD
  
  strip.setBrightness(50);//Pixel 3 BLAUW
  strip.show(); //Laat de kleuren zien!
 
  knop1 = "active";
 

      if (digitalRead(13) == HIGH)
      {
        strip.clear();
        level = 1;      
      }
      if (digitalRead(12) == HIGH) 
         
         
      {
        fout();
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
    
    if (strip.getPixelColor(2) != 0x000000)
    {
      Serial.println("2");
      if (digitalRead(2) == HIGH)
      {
        strip.clear();
        level = 2;
      }
      if ((digitalRead(3) == HIGH)  || 
          (digitalRead(13) == HIGH)  ||
          (digitalRead(12) == HIGH) ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        fout();
      }
    }
    
    if (strip.getPixelColor(3) != 0x000000)
    {
    Serial.println("3");
      if (digitalRead(3) == HIGH)
      {
        strip.clear();
        level = 2;
      }
      if ((digitalRead(2) == HIGH)  || 
          (digitalRead(12) == HIGH) ||
          (digitalRead(13) == HIGH) ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        fout();
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
    
    if (strip.getPixelColor(4) != 0x000000)
    {
      Serial.println("4");
      if (digitalRead(4) == HIGH)
      {
        strip.clear();
        level = 3;
      }
      if ((digitalRead(5) == HIGH)  || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(13) == HIGH) ||
          (digitalRead(12) == HIGH) ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        fout();
      }
    }
    
    if (strip.getPixelColor(5) != 0x000000)
    {
    Serial.println("5");
      if (digitalRead(5) == HIGH)
      {
        strip.clear();
        level = 3;
      }
      if ((digitalRead(4) == HIGH)  || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(12) == HIGH) ||
          (digitalRead(13) == HIGH) ||
          (digitalRead(6) == HIGH)  ||
          (digitalRead(7) == HIGH)
         )
      {
        fout();
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
    
    if (strip.getPixelColor(6) != 0x000000)
    {
      Serial.println("6");
      if (digitalRead(6) == HIGH)
      {
        strip.clear();
        level = 4;
      }
      if ((digitalRead(7) == HIGH) || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(13) == HIGH) ||
          (digitalRead(12) == HIGH)
         )
      {
        fout();
      }
    }
    
    if (strip.getPixelColor(7) != 0x000000)
    {
    Serial.println("7");
      if (digitalRead(7) == HIGH)
      {
        strip.clear();
        level = 4;
      }
      if ((digitalRead(6) == HIGH) || 
          (digitalRead(2) == HIGH)  ||
          (digitalRead(3) == HIGH)  ||
          (digitalRead(4) == HIGH)  ||
          (digitalRead(5) == HIGH)  ||
          (digitalRead(12) == HIGH) ||
          (digitalRead(13) == HIGH)
         )
      {
        fout();
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
    
   gehaald();
    
  }
  /*
 
  if (level == 2) {
   
   
  strip.show(); //Laat de kleuren zien!
  strip.setPixelColor(4, 255, 0, 0); //Pixel 3 BLAUW
  strip.setBrightness(50);//Pixel 3 BLAUW
      }  */
/*
  knop1 = "active";
 
      if (digitalRead(buttonpin) == HIGH){
        level = 2;
      }
  }
  */
 

}
