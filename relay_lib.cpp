#include "relay_lib.hpp"

Relay::Relay() {
  
}

Relay::Relay(const int p, const bool no) {
  this->pin = p;
  this->normallyOpen = no;
  if(this->normallyOpen == true) {
    state = 0;
  }
  else {
    state = 1;
  }
  pinMode(this->pin, OUTPUT);
}

Relay::~Relay() {
  
}

void Relay::setRelay(const int p, const bool no) {
  pin = p;
  normallyOpen = no;
  if(normallyOpen == true) {
    state = 0;
  }
  else {
    state = 1;
  }
  pinMode(pin, OUTPUT);
}

bool Relay::getState() {
  if(normallyOpen == true) {
    return state;
  }
  else{
    return !state;
  }
}

void Relay::turnOn() {
  if(state == 0) {
    digitalWrite(pin, !state);
    state =! state;
  }
}

void Relay::turnOff() {
  if(state == 1) {
    digitalWrite(pin, !state);
    state =! state;
  }
}
