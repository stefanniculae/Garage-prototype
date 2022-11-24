#include "HCSR04_lib.hpp"

HCSR04::HCSR04() {
  
}

HCSR04::HCSR04(const int e, const int t) {
  this->trig = t;
  this->echo = e;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

HCSR04::~HCSR04() {

}

void HCSR04::setPins(const int e, const int t) {
  trig = t;
  echo = e;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

float HCSR04::getDist() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void HCSR04::printDist() {
  Serial.print("Distance: ");
  Serial.print(this->getDist());
  Serial.println(" cm");
}
