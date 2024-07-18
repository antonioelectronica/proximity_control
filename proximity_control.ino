// Pin declaration
const int ledPins[] = {A3, A4, A5}; // Pins for LEDs
const int sensorPins[] = {A0, A1, A2}; // Pins for proximity sensors
const int threshold = 700; // Threshold for proximity detection
const int numSensors = 3;

float sensorValues[numSensors];

void setup() {
  // Pin initialization
  for (int i = 0; i < numSensors; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(sensorPins[i], INPUT);
    digitalWrite(ledPins[i], LOW); // Initialize LEDs as off
  }

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  readSensors();
  printSensorValues();
  controlLeds();
  delay(250);
}

void readSensors() {
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
}

void printSensorValues() {
  for (int i = 0; i < numSensors; i++) {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(sensorValues[i]);
  }
}

void controlLeds() {
  if (allSensorsBelowThreshold(threshold)) {
    turnOnLeds(true, true, true);
  } else if (sensorValues[0] < threshold && sensorValues[1] < threshold && sensorValues[2] >= threshold) {
    turnOnLeds(true, true, false);
  } else if (sensorValues[0] < threshold && sensorValues[1] >= threshold && sensorValues[2] >= threshold) {
    turnOnLeds(true, false, false);
  } else {
    turnOnLeds(false, false, false);
  }
}

bool allSensorsBelowThreshold(int value) {
  for (int i = 0; i < numSensors; i++) {
    if (sensorValues[i] >= value) {
      return false;
    }
  }
  return true;
}

void turnOnLeds(bool led1, bool led2, bool led3) {
  digitalWrite(ledPins[0], led1 ? HIGH : LOW);
  digitalWrite(ledPins[1], led2 ? HIGH : LOW);
  digitalWrite(ledPins[2], led3 ? HIGH : LOW);
}
