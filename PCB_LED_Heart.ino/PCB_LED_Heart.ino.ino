// Compile for Arduino Leonardo
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 14
#define DATA_PIN 5  

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
	FastLED.setBrightness(15);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
  for(int i = 0; i<7; i++) {
    static uint8_t hue = 0;
    // First slide the led in one direction
    for(int i = 0; i < NUM_LEDS; i++) {
      // Set the i'th led to red 
      hue+=2;
      leds[i] = CHSV(hue, 255, 255);
      // Show the leds
      FastLED.show(); 
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      // Wait a little bit before we loop around and do it again
      delay(50);
    }
  }
  for(int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CHSV(100, 100, 100);
    leds[NUM_LEDS-i - 1] = CHSV(100,100,100);
    FastLED.show();
    fadeall();
    delay(150);
  }
}
