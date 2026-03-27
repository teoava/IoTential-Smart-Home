#include <Servo.h>

Servo servo;
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distance;

void setup() {
  servo.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Trimite semnalul ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculează durata și distanța
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Dacă distanța este mai mică de 25 cm, deschide capacul
  if (distance < 25) {
    servo.write(90); // Deschide
    delay(3000);     // Menține deschis 3 secunde
  } else {
    servo.write(0);  // Închide
  }
  
  delay(100);
}
