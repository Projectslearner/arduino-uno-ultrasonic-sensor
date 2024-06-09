/*
    Project name : Ultrasonic Sensor
    Modified Date: 09-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-ultrasonic-sensor
*/

#define trigPin 9 // Trig pin of the sensor connected to Arduino pin 9
#define echoPin 10 // Echo pin of the sensor connected to Arduino pin 10

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigPin as an output
  pinMode(echoPin, INPUT); // Set echoPin as an input
}

void loop() {
  long duration, distance; // Variables to hold the duration and calculated distance

  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound (343 m/s or 0.0343 cm/microsecond)
  distance = (duration * 0.0343) / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Delay before taking the next measurement
}
