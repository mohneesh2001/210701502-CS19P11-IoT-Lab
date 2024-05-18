
// Pin definitions
const int pirPin = 2;      // PIR motion sensor pin
const int soundPin = 3;    // Sound detection sensor pin
const int rainPin = 4;     // Rain detection sensor pin
const int ledPin = 13;     // LED pin
const int buzzerPin = 5;   // Buzzer pin

// Variables
int pirState = LOW;        // Initialize PIR sensor state
int soundState = LOW;      // Initialize sound sensor state
int rainState = LOW;       // Initialize rain sensor state
unsigned long lastBuzzTime = 0;  // Last time buzzer was toggled

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(soundPin, INPUT);
  pinMode(rainPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Begin serial communication for debugging
}

void loop() {
  // Read sensor inputs
  pirState = digitalRead(pirPin);
  soundState = digitalRead(soundPin);
  rainState = digitalRead(rainPin);
  delay(1000);
  
  // If any sensor detects activity, turn on the LED and buzzer
  if (pirState == HIGH || soundState == HIGH || rainState == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW); // Turn on buzzer when any sensor detects something
    
    // Print sensor detection messages
    if (pirState == HIGH) {
      Serial.println("The Baby is moving!!");
    }
    if (soundState == HIGH) {
      Serial.println("The baby is crying!!");
    }
    if (rainState == HIGH) {
      Serial.println("The carddle is currently wet!!");
    }
    
    delay(3000);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, HIGH); // Turn off buzzer when no sensor detects anything
  }
}


