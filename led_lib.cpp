#include "led_lib.hpp"

Led::Led() {

}

Led::Led(const int p) {
  pin = p;
  state = false;
  pinMode(p, INPUT);
}

Led::~Led() {

}

void Led::setPin(const int p) {
  pin = p;
  state = false;
  pinMode(pin, OUTPUT);
}

bool Led::getState() {
  return state;
}

void Led::turnOn() {
  digitalWrite(pin, HIGH);
  state = true;
}

void Led::turnOff() {
  digitalWrite(pin, LOW);
  state = false;
}