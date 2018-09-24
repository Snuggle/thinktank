// IN1/IN2 represent the directionality of the left motors
// while IN3/IN4 are for right side.


// Define the IO pins
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); // We need to set the IO pins to output mode
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite(ENA, HIGH); // Enable the left motors
  digitalWrite(ENB, HIGH);
}



void left() {
  digitalWrite(IN1, LOW); // Left motor stopped
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // Right motor forward
  digitalWrite(IN4, HIGH);
}

void right () {
  digitalWrite(IN1, HIGH); // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // Right motor stopped
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH); // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // Right motor forward
  digitalWrite(IN4, HIGH);
}

void backward() {
  digitalWrite(IN1, LOW); // Left motor backwards
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); // Right motor backwards
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(IN1, LOW); // All motors stopped
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void fast(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void brake(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENA, LOW);
}

void loop() {
  left();
  delay(1000);
  right();
  delay(1000);
  brake();
  delay(1000);
  forward();
  delay(1000);
  backward();
  delay(1000);
  stop();
  delay(1000);
}
