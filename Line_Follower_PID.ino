/*
 Sensor1 -> 5
 Sensor2 -> 6
 Sensor3 -> 7
 Sensor4 -> 8
 Sensor5 -> 9
 Sensor6 -> 10
 */

#include <QTRSensors.h>

#define KP 0.2
#define KD 5
#define NUM_SENSORS 6
#define TIMEOUT 2500
#define EMITTER_PIN 2

int lastError = 0, output = 0, error, position;

QTRSensorsRC qtrrc((unsigned char[]) {
  10, 9, 8, 7, 6, 5
} , NUM_SENSORS, TIMEOUT, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];

void setup() {
  pinMode(2, INPUT);   // BUTON
  pinMode(4, OUTPUT);  // LED
  pinMode(3, OUTPUT);  // PWM
  pinMode(11, OUTPUT); // PWM
  pinMode(12, OUTPUT); // Direction
  pinMode(13, OUTPUT); // Direction
  digitalWrite(4,0);   // LED Off
  
  manual_calibration();
  kontrol();
}

void loop() {
  unsigned int sensors[6];
  position = qtrrc.readLine(sensors);
  error = position - 2500;

  output = KP * error + KD * (error - lastError);
  lastError = error;

  if (output >= 40)
    output = 40;

  else if (output <= -40)
    output = -40;

  ileri(output);
}

void kontrol(){
  digitalWrite(4,1); // LED ON
  while(digitalRead(2)==0);
  digitalWrite(4,0); // LED Off
}

void ileri(int hiz) {
  analogWrite(3, 50 - hiz); // speed
  digitalWrite(12, HIGH);
  analogWrite(11, 50 + hiz); // speed
  digitalWrite(13, HIGH);
}

void manual_calibration() {
  for (int i = 0; i < 250; i++) {
    qtrrc.calibrate(QTR_EMITTERS_ON);
    delay(20);
  }
}
