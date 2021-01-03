#include <FastLED.h> 

#define NUM_LEDS 300
#define DATA_PIN 6
#define AMTOFLEDS 1

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2811,DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600); 
  FastLED.clear(); 
  FastLED.show(); 
}

void loop()
{ 
  if(Serial.read() > 0)
  {
    for(int i = 0; i < AMTOFLEDS; i++)
    {
      leds[i] = CRGB(0,255,0);
    }
  }    
  else
  {
    for(int i = 0; i < AMTOFLEDS; i++)
    {
      leds[i] = CRGB(0,0,0);
    } 
  }
  FastLED.show(); 
  //always shifts the pixels
  for(int i = NUM_LEDS - 1; i >= AMTOFLEDS; i--) 
  {
    leds[i] = leds[i - AMTOFLEDS];
  }
  FastLED.show(); 
} 
  
