#include "button_lib.hpp"

Button::Button() {

}

Button::Button(const int p) {
  pin = p;
  state = false;
  pinMode(p, INPUT);
}

Button::~Button() {

}

void Button::setPin(const int p) {
  pin = p;
  state = false;
  pinMode(pin, INPUT);
}

bool Button::getState() {
  if(digitalRead(pin) == state) {
    return state;
  }
  else {
    return !state;
  }
}
