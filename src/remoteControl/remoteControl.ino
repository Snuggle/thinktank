#include <IRremote.h>
#include <IRremoteInt.h>

// IR Remote Codes
#define F 16736925
#define B 16754775
#define L 16720605
#define R 16761405
#define S 16712445
#define UNKNOWN_F 5316027
#define UNKNOWN_B 2747854299
#define UNKNOWN_L 1386468383
#define UNKNOWN_R 553536955
#define UNKNOWN_S 3622325019

#define RECV_PIN 12
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 255

IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long val;
unsigned long preMillis;

void setup() {
  Serial.begin(9600);
  Serial.print("Hello and welcome to the ThinkTank! You are currently viewing DEBUG output.\n[=========================================================================");
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  irrecv.enableIRIn();
  enableMotors();
}

void loop() {
  if (irrecv.decode(&results)){
    preMillis = millis();
    val = results.value;
    //Serial.println(val);
    irrecv.resume();
    switch(val){
      case S:
      case UNKNOWN_S: move(0); Serial.print("]\nStopping\n["); break;
      case F:
      case UNKNOWN_F: move(1); Serial.print("]\nMoving forward\n["); break;
      case B:
      case UNKNOWN_B: move(2); Serial.print("]\nMoving backward\n["); break;
      case L:
      case UNKNOWN_L: move(3); Serial.print("]\nMoving left\n["); break;
      case R:
      case UNKNOWN_R: move(4); Serial.print("]\nMoving right\n["); break;
      case 4294967295: Serial.print("."); break;
      default: Serial.println("\n"+val); break;
    }
  }
  else {
    if(millis() - preMillis > 130) {
      disableMotors();
      preMillis = millis();
    }
  }
}
