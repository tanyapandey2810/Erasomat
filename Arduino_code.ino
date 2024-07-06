#include <Servo.h>
const int switchPin1 = 4; 
const int switchPin2 = 3;
const int switchPin3 = 2; 
const int motorIn1 = 7;   
const int motorIn2 = 6;   
Servo servo1;
int pos1 = 0;
int pos2 = 90;
int x=0;
void forward() {
  digitalWrite(motorIn1, HIGH); 
  digitalWrite(motorIn2, LOW);  
}

void backward() {
  digitalWrite(motorIn1, LOW);  
  digitalWrite(motorIn2, HIGH); 
}

void stopMotor() {
  digitalWrite(motorIn1, LOW);  
  digitalWrite(motorIn2, LOW);  
}


void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP); 
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
  
}

void loop() {
  if(Serial.available()>0){
    int rec=Serial.read(); 
    if(rec==65){
      servotest();
      }
    }

  if (digitalRead(switchPin1) == LOW) {
    Serial.println("SW 1 Pressed");
    forward(); 
    while (digitalRead(switchPin1) == LOW) {} 
    stopMotor(); 
  }
  
  
  if (digitalRead(switchPin2) == LOW) {
    Serial.println("SW 2 Pressed");
    backward(); 
    while (digitalRead(switchPin2) == LOW) {} 
    stopMotor(); 
  }
   if (digitalRead(switchPin3) == LOW) {
    Serial.println("SW 3 Pressed");
    forward();
    for(x=0;x<90;x++){
    servo1.write(x);
    delay(5);
     }
    while (digitalRead(switchPin1) == LOW) {} 
    stopMotor(); 
    for(x=90;x>0;x--){
    servo1.write(x);
    delay(5);
  }

  }
}

void servotest(){
  Serial.println("90");
  for(x=0;x<90;x++){
    servo1.write(x);
    delay(5);
  }
  Serial.println("0");
  for(x=90;x>0;x--){
    servo1.write(x);
    delay(5);
  }
}
