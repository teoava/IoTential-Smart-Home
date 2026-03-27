#include <Servo.h>

Servo myservo; // creează un obiect de tip servo pentru a controla servomotorul
int rainSensorPin = A0; // pinul analogic la care este conectat senzorul de ploaie
int sensorValue = 0; // variabilă pentru a stoca valoarea citită de la senzor

void setup() {
  myservo.attach(9); // atașează servomotorul la pinul 9
  pinMode(rainSensorPin, INPUT); // setează pinul senzorului ca intrare
  Serial.begin(9600); // inițializează comunicarea serială pentru monitorizare
}

void loop() {
  sensorValue = analogRead(rainSensorPin); // citește valoarea de la senzorul de ploaie
  Serial.print("Rain Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > 800) { // pragul pentru detectarea apei (ajustabil)
    myservo.write(90); // mută servomotorul la 90 de grade pentru a proteja hainele
    delay(1000); // așteaptă o secundă
  } else {
    myservo.write(0); // readuce servomotorul la poziția inițială
    delay(1000); // așteaptă o secundă
  }
}
