// Simple modular library for moving the robot.

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
