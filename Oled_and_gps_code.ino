#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define GPS_SERIAL Serial1 

TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  GPS_SERIAL.begin(9600); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  
  display.clearDisplay();
  display.display();
}

void loop() {
  while (GPS_SERIAL.available() > 0) {
    if (gps.encode(GPS_SERIAL.read())) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);

      if (gps.location.isValid()) {
        display.print("Latitude: ");
        display.println(gps.location.lat(), 6);
        display.print("Longitude: ");
        display.println(gps.location.lng(), 6);
      } else {
        display.println("Waiting for GPS...");
      }

      display.display();
    }
  }
}
