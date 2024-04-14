#include <SoftwareSerial.h>

#define GPS_RX_PIN 4 
#define GPS_TX_PIN 3

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN); 

void setup() {
  Serial.begin(9600); 
  gpsSerial.begin(9600); 
}

void loop() {
  if (gpsSerial.available() > 0) { 
    if (gpsSerial.find("$GPGGA")) { 
      bool fix = checkFix(); 
      if (fix) {
        Serial.println("GPS fix acquired"); 
      } else {
        Serial.println("No GPS fix"); 
      }
    }
  }
}

bool checkFix() {
  char buffer[100];
  gpsSerial.readBytesUntil('\n', buffer, sizeof(buffer)); 
  char *token = strtok(buffer, ","); 
  while (token != NULL) {
    if (strncmp(token, "$GPGGA", 6) == 0) { 
      for (int i = 0; i < 5; i++) {
        token = strtok(NULL, ","); 
      }
      if (atoi(token) == 0) { 
        return false;
      } else {
        return true;
      }
    }
    token = strtok(NULL, ","); 
  }
  return false; 
}
