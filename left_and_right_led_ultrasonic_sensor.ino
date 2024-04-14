
const int trigPin = 9;
const int echoPin = 10;


const int leftLedPin = 13;
const int rightLedPin = 12;

void setup() {
  // Set the LED pins as OUTPUT
  pinMode(leftLedPin, OUTPUT);
  pinMode(rightLedPin, OUTPUT);

  // Set the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  
  int distance = duration / 58;

  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance < 30) {
    
    digitalWrite(leftLedPin, LOW);
    digitalWrite(rightLedPin, HIGH);
  } else {
    // No object detected, turn on left LED
    digitalWrite(leftLedPin, HIGH);
    digitalWrite(rightLedPin, LOW);
  }

  
  delay(500);
}
