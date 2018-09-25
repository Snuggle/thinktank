#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define LED 13

bool state = LOW;
char getstr;
unsigned int speed;



void toggleLED() {
  state = !state;
  digitalWrite(LED, state);
  Serial.println("Light");
}

void setup () {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  speed = 100;
  //move(0);
}

void enableMotors(int speed){ // Enable the motors.
  //digitalWrite(ENA, HIGH);
  //digitalWrite(ENB, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void disableMotors(){ // Disable motors.
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

// direction: 0 stop, 1 forward, 2 backward, 3 left, 4 right.
void move(int direction, int speed=255) { // Default is full-speed.
  enableMotors(speed);
  switch (direction) {
    case 0: // Stop
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      disableMotors();
    case 1: // Forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 2: // Backward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 3: // Left
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 4: // Right
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
  }
}


void loop() {
  getstr = Serial.read();
  switch(getstr){
    case '.': move(0, speed); break;
    case '^': move(1, speed); break;
    case 'v': move(2, speed); break;
    case '<': move(3, speed); break;
    case '>': move(4, speed); break;
    case 'L': toggleLED(); break;
    case 'U':
      speed = 255;
      break;
    case 'H':
      speed = 200;
      break;
    case 'D':
      speed = 100;
      break;
    default: break;
  }
}
