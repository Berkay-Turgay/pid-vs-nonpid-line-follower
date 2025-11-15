#include <QTRSensors.h>

#define NUM_SENSORS   6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

QTRSensorsRC qtrrc((unsigned char[]) {
  5, 6, 7, 8, 9, 10
},
NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

int current_pos = 0;

void setup() {
  pinMode(3, HIGH);
  pinMode(11, HIGH);
  pinMode(12, HIGH);
  pinMode(13, HIGH);

  delay(1000);
  ileri();
}

void loop() 
{
  detect_pos();

  if (current_pos == -5 || current_pos == -4 || current_pos == -3 || current_pos == -2 )
  {
    sol();

    while ( current_pos != -1 && current_pos != 0 && current_pos != 1  ) {
      detect_pos();
      delay(10);
    }
    ileri();
  }

  else if (current_pos == 5 || current_pos == 4 || current_pos == 3 || current_pos == 2)
  {
    sag();

    while ( current_pos != -1 && current_pos != 0 && current_pos != 1  ) {
      detect_pos();
      delay(10);
    }
    ileri();
  }

  delay(10);
}

void sag() {
  analogWrite(3, 50); // speed
  digitalWrite(12, HIGH);
  analogWrite(11, 50); // speed
  digitalWrite(13, LOW);
}

void sol() {
  analogWrite(3, 50); // speed
  digitalWrite(12, LOW);
  analogWrite(11, 50); // speed
  digitalWrite(13, HIGH);
}

void ileri() {
  analogWrite(3, 60); // speed
  digitalWrite(12, HIGH);
  analogWrite(11, 60); // speed
  digitalWrite(13, HIGH);
}

void detect_pos() {
  qtrrc.read(sensorValues);

  if ( sensorValues[0] >= 1000 && sensorValues[1] >= 1000 )
    current_pos = -4;

  else if ( sensorValues[1] >= 1000 && sensorValues[2] >= 1000 )
    current_pos = -2;

  else if ( sensorValues[2] >= 1000 && sensorValues[3] >= 1000 )
    current_pos = 0;

  else if ( sensorValues[3] >= 1000 && sensorValues[4] >= 1000 )
    current_pos = 2;

  else if ( sensorValues[4] >= 1000 && sensorValues[5] >= 1000 )
    current_pos = 4;

  else if (sensorValues[0] >= 1000)
    current_pos = -5;

  else if (sensorValues[1] >= 1000)
    current_pos = -3;

  else if (sensorValues[2] >= 1000)
    current_pos = -1;

  else if (sensorValues[3] >= 1000)
    current_pos = 1;

  else if (sensorValues[4] >= 1000)
    current_pos = 3;

  else if (sensorValues[5] >= 1000)
    current_pos = 5;
}
