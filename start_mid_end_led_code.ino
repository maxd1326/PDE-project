#include <Adafruit_NeoPixel.h>

#define LED_PIN    13
#define LED_COUNT  10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); 
}

void loop() {
  // Light up first 3 LEDs
  for(int i = 0; i < 3; i++) {
    strip.setPixelColor(i, 20, 0, 0);  
  }
  strip.show();
  delay(1000);
  
  for(int i = 0; i < 3; i++) {
    strip.setPixelColor(i, 0, 0, 0); 
  }
  strip.show();
  delay(1000);
  
  
  // Light up middle 4 LEDs
  for(int i = 3; i < 7; i++) {
    strip.setPixelColor(i, 20, 0, 0);  
  }
  strip.show();
  delay(1000);
  
  for(int i = 3; i < 7; i++) {
    strip.setPixelColor(i, 0, 0, 0);  
  }
  strip.show();
  delay(1000);

  // Light up last 3 LEDs
  for(int i = 7; i < 10; i++) {
    strip.setPixelColor(i, 20, 0, 0);  
  }
  strip.show();
  delay(1000);

  // Turn off all LEDs
  for(int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, 0, 0, 0);  
  }
  strip.show();
  delay(1000);
}  
