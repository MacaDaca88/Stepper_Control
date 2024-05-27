
bool clockwise = false;
bool anticlockwise = false;

#define STEPS 200

void stepSetup() {

  pinMode(DIRpin, OUTPUT);
  pinMode(STEPpin, OUTPUT);
  pinMode(STEPpwrPIN, OUTPUT);
}

void stepRunClockwise() {
  digitalWrite(STEPpwrPIN, 1);  // turn steeper in Clockwise rotation

  digitalWrite(DIRpin, 1);  // turn steeper in Clockwise rotation
  Serial.println(STEPS);

  for (int x = 0; x < STEPS; x++) {
    digitalWrite(STEPpin, 1);
    delayMicroseconds(500);
    digitalWrite(STEPpin, 0);
    delayMicroseconds(500);
  }
  digitalWrite(STEPpwrPIN, 0);  // turn steeper in Clockwise rotation
}

void stepRunAntiClockwise() {
  digitalWrite(STEPpwrPIN, 1);  // turn steeper in Clockwise rotation

  digitalWrite(DIRpin, 0);  // turn steeper in Anti-clockwise rotation
  Serial.println(STEPS);
  for (int x = 0; x < STEPS; x++) {
    digitalWrite(STEPpin, 1);
    delayMicroseconds(500);
    digitalWrite(STEPpin, 0);
    delayMicroseconds(500);
  }
  digitalWrite(STEPpwrPIN, 0);  // turn steeper in Clockwise rotation
}