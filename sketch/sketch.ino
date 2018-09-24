// Define the IO pins
#define ENA 5
#define IN1 7
#define IN2 8

void setup() {
  pinMode(IN1, OUTPUT); //
  pinMode(IN2, OUTPUT); // We need to set the IO pins to output mode
  pinMode(ENA, OUTPUT); //
  digitalWrite(ENA, HIGH); // Enable the left motors
}

void loop() {
  digitalWrite(IN1, HIGH); //
  digitalWrite(IN2, LOW); //The left wheels should turn forwards
  delay(1000); // Wait 1 second
  digitalWrite(IN1, LOW); // Stop
  digitalWrite(IN2, LOW); //
  delay(1000);
}
