#include <FastLED.h> 

#define NUM_LEDS 300
#define DATA_PIN 6
#define updateLEDS 1

CRGB leds[NUM_LEDS];
const unsigned long ledShiftTime = 10000000;
unsigned int dottt= 0; 
unsigned int dot = 0;
unsigned int dot2 = 0; 
unsigned long previousTime1 = 0; 
unsigned long previousTime2 = 0; 

void setup()
{
  FastLED.addLeds<WS2811,DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(115200); 
  
  FastLED.clear(); 
  FastLED.show(); 
}

void loop()
{ 
  if(Serial.read() > 0)
  {
    for(int i = 0; i < updateLEDS; i++)
    {
      leds[i] = CRGB(0,255,0);
    }
  }    
  else
  {
    for(int i = 0; i < updateLEDS; i++)
    {
      leds[i] = CRGB(0,0,0);
    } 
  }
  FastLED.show(); 
  //always shifts the pixels by updateLEDs even when no color
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) 
  {
    leds[i] = leds[i - updateLEDS];
  }
  FastLED.show(); 
} 
  
   
