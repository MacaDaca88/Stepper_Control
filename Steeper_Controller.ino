
#include "pins.h"
#include "step.h"
#include "bluetooth.h"

void setup() {

  stepSetup();
  Serial.begin(115200);
  SerialBT.begin("Steepper Controller");
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, 1);
}

void loop() {

  BTloop();

  if (clockwise) {
    anticlockwise = false;
    stepRunClockwise();
  }

  if (anticlockwise) {
    clockwise = false;
    stepRunAntiClockwise();
  }
}
