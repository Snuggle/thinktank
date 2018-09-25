#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeedTurning 5 // TODO: Blank variable, replaced with 5.

unsigned char carSpeed = X // TODO: Blank variable, replaced with X.
bool state = LOW;
char getstr;

void stateChange() {
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
  stop(); // TODO
}

void loop() {
  getstr = Serial.read();
  switch(getstr){
    case 's': stop(); break;
    case 'f': forward(); break;
    case 'b': backward(); break;
    case 'l': left(); break;
    case 'r': right(); break;
    case 'a': stateChange(); break;
    default: break;
  }
}
