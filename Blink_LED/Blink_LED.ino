int LED_BUILTIN_red = 33;
int flash = 4;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN_red, OUTPUT);
  pinMode(flash, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN_red, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(flash, HIGH);   
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN_red, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(flash, LOW);
  delay(1000);                       // wait for a second
} 