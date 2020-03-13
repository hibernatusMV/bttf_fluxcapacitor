int fluxLed[4] = {9, 10, 11, 12};
int x, i;

void setup() {
  // initialize digital pin fluxLed as an output.
  for (int x=0; x < 3; x++) {
    pinMode(fluxLed[x], OUTPUT);
  }
}

void loop() {
  for (int i=0; i<=3; i++) {
    digitalWrite(fluxLed[i], HIGH);
    delay(50);
    digitalWrite(fluxLed[i], LOW);
    delay(50);
  }
}
