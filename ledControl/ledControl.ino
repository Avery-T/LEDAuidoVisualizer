#include <Adafruit_NeoPixel.h> 
#ifdef __AVR__ 
#endif

#define NUMPIXELS 60
#define PIN 6 
Adafruit_NeoPixel pixels(NUMPIXELS,PIN, NEO_GRB + NEO_KHZ800); 

void setup() 
{
  pixels.begin(); 
  Serial.begin(9600); 
}

void loop() 
{
  if(Serial.read() > 0)
  {
    if(Serial.read() > 70)
    {
      pixels.fill((255,0,0),0,50);
      pixels.show();
    }
    else
    {
      pixels.fill((0,0,255), 0, 50);
      pixels.show();  
    }
    
  }
  pixels.clear(); 
  pixels.show();
  
}
