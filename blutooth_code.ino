#include <Adafruit_NeoPixel.h>

#define LED_PIN           13
#define LED_COUNT         10  
#define LED_DEGREE_SPREAD 36 

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int currentLED = -1;
uint32_t color;
int brightness = 255; 

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); 
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.startsWith("brightness")) {
      brightness = input.substring(11).toInt();
      brightness = constrain(brightness, 0, 255); 
      strip.setBrightness(brightness);
      strip.show();

      
      Serial.print("Brightness level set to: ");
      Serial.println(brightness);
    } else {
      int spaceIndex = input.indexOf(' ');
      if (spaceIndex != -1 && input.length() > spaceIndex + 1) {
        String colorStr = input.substring(0, spaceIndex);
        String degreeStr = input.substring(spaceIndex + 1);
        int degree = degreeStr.toInt();
        if (degree >= 0 && degree <= 360) {
          int ledIndex = map(degree, 0, 360, 0, LED_COUNT);
          if (colorStr.equalsIgnoreCase("red")) {
            color = strip.Color(255, 0, 0);
          } else if (colorStr.equalsIgnoreCase("green")) {
            color = strip.Color(0, 255, 0);
          } else if (colorStr.equalsIgnoreCase("blue")) {
            color = strip.Color(0, 0, 255);
          } else {
            Serial.println("Invalid color input! Please enter 'red', 'green', or 'blue'.");
            return;
          }
          if (ledIndex != currentLED) {
            if (currentLED != -1) {
              turnOffLED(currentLED);
            }
            turnOnLED(ledIndex, color);
            currentLED = ledIndex;
          }
        } else {
          Serial.println("Invalid degree input! Please enter a value between 0 and 360.");
        }
      } else {
        Serial.println("Invalid input format! Please enter the color (red, green, or blue) followed by the degree value.");
      }
    }
  }
}

void turnOnLED(int ledIndex, uint32_t color) {
  strip.setPixelColor(ledIndex, color);
  strip.show();
}

void turnOffLED(int ledIndex) {
  if (ledIndex >= 0 && ledIndex < LED_COUNT) {
    strip.setPixelColor(ledIndex, 0); // Turn off the LED at the given index
    strip.show();
  }
}


