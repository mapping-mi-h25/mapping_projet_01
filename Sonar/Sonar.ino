const int trigPin = 9; // Pin connected to Trig
const int echoPin = 10; // Pin connected to Echo
long duration;
float distance;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and measure the time it takes
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (speed of sound: 343 m/s or 0.034 cm/us)
  distance = (duration * 0.034) / 2;

  // Display the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Delay for readability
}