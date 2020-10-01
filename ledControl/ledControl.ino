#include <FastLED.h> 

#define NUM_LEDS 60
#define DATA_PIN 6
#define updateLEDS 1

CRGB leds[NUM_LEDS];
const unsigned long ledShiftTime = 10000000;
unsigned int dottt= 0; 
unsigned int dot = 0;
unsigned int dot2 = 0; 
unsigned long previousTime1 = 0; 
unsigned long previousTime2 = 0; 
 
if(Serial.read() > 0)
{
  for(int i = 0; i < updateLEDS; i++)
  {
    leds[i] = CRGB(160,32,240);
  }
  FastLED.show();   
}

else
{
  for(int i = 0; i < updateLEDS; i++)
  {
    leds[i] = CRGB(0,0,0);
  }
  
  FastLED.show(); 
}
  //always shifts the pixels by updateLEDs even when no color
  
for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) 
{
  leds[i] = leds[i - updateLEDS];
}

FastLED.show(); 
  
   

