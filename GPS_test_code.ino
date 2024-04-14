#include <SoftwareSerial.h>

// Define the pins for the LED and GPS module
const int ledPin = 13; // Pin connected to the LED
const int gpsTxPin = 3; // TX pin of GPS module connected to Arduino's pin 3
const int gpsRxPin = 4; // RX pin of GPS module connected to Arduino's pin 4

// Create a SoftwareSerial object to communicate with the GPS module
SoftwareSerial gpsSerial(gpsTxPin, gpsRxPin);

void setup() {
  // Initialize serial communication with the PC
  Serial.begin(9600);
  
  // Initialize serial communication with the GPS module
  gpsSerial.begin(9600);
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Check if data is available from the GPS module
  if (gpsSerial.available() > 0) {
    // Read the incoming character from the GPS module
    char gpsData = gpsSerial.read();
    
    // Check if the received character indicates valid GPS data
    if (gpsData == '$') {
      // Valid GPS data received, turn on the LED
      digitalWrite(ledPin, HIGH);
      Serial.println("GPS module connected!");
      // Wait for a while before turning off the LED
      delay(5000); // 5 seconds delay
      digitalWrite(ledPin, LOW); // Turn off the LED
    }
  }
}
