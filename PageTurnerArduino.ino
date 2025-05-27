const int leftSensor = 7;       // PIR sensor connected to digital pin 7
const int rightSensor = 8;
const int ledPin = 13;      // Built-in LED for visual motion indication
int leftState = LOW;         // Current motion state
int rightState = LOW;
int leftVal = 0;                // PIR raw leftValue
int rightVal = 0;

void setup() {
  pinMode(leftSensor, INPUT);     // Set PIR pin as input
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  Serial.begin(9600);         // Start serial communication
  Serial.println("Waiting for calibration: ");

  // Wait for 60 seconds and show progress bar
  for (int i = 0; i <= 60; i++) {
  Serial.print("Time elapsed: ");
  Serial.print(i);
  Serial.print("s ");
  
  // Visual progress bar of 20 characters
  Serial.print("[");
  int progress = map(i, 0, 60, 0, 20);  // Map seconds to progress bar size
  for (int j = 0; j < 20; j++) {
    if (j < progress) {
      Serial.print("#");  // Filled part
    } else {
      Serial.print(" ");  // Empty part
    }
  }
  Serial.println("]");

  delay(1000);  // Delay 1 second
  }
  Serial.println("PIR Motion Sensor Debug Started");
}

void loop() {
  leftVal = digitalRead(leftSensor);   // Read PIR sensor leftValue
  rightVal = digitalRead(rightSensor);

  // Print raw leftValue to Serial Monitor
 // Serial.print("Left PIR raw value: ");
  //Serial.println(leftVal);

  // Print raw rightValue to Serial Monitor
  //Serial.print("Right PIR raw value: ");
  //Serial.println(rightVal);

  // TODO:
  // Handle left and right vals

  // Light the LED if motion is detected
  //digitalWrite(ledPin, leftVal);

  // Print motion start/end messages
  if (leftVal == HIGH && leftState == LOW) {
    Serial.println("Motion detected on Left Sensor!");
    Serial.println("LEFT");
    leftState = HIGH;
  } else if (leftVal == LOW && leftState == HIGH) {
    Serial.println("Motion ended on Left Sensor.");
    leftState = LOW;
  }

   // Print motion start/end messages
  if (rightVal == HIGH && rightState == LOW) {
    Serial.println("Motion detected on Right Sensor!");
    Serial.println("RIGHT");  // Signal to go to next page
    rightState = HIGH;
  } else if (rightVal == LOW && rightState == HIGH) {
    Serial.println("Motion ended on Right Sensor.");
    rightState = LOW;
  }

  delay(500); // Delay for stability
}