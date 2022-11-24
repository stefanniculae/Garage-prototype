#include "HCSR04_lib.hpp"
#include "relay_lib.hpp"
#include "DHT11_lib.hpp"
#include "button_lib.hpp"
#include "led_lib.hpp"

HCSR04 ultrasonicSensor;
Relay light, fan;
DHT11 dht;
Button b1, b2;
Led red, yellow, green;

void setup() {
  dht.setPin(2);
  Serial.begin(9600);
  ultrasonicSensor.setPins(3,4);
  light.setRelay(5, true);
  fan.setRelay(6, true);
  b1.setPin(7);
  b2.setPin(8);
  red.setPin(9);
  yellow.setPin(10);
  green.setPin(11);
  delay(2000);
}

void loop() {
  lightChecker();
  temperatureControl();
  if(b2.getState() == true) {
    while(b2.getState() == true) {
      
    }
    sensorOn();
  }
  delay(100);
}

void temperatureControl() {
  if(dht.getTemperatureCelsius() > 25) {
    fan.turnOn();
  }
  else {
    fan.turnOff();
  }
}

void lightChecker() {
  if(b1.getState() == true && light.getState() == false) {
    light.turnOn();
    Serial.println("LIGHT ON");
    while(b1.getState() == true) {

    }
  }
  else if(b1.getState() == true && light.getState() == true){
    light.turnOff();
    Serial.println("LIGHT OFF");
    while(b1.getState() == true) {
      
    }
  }
}

void sensorOn() {
  while(b2.getState() == false) {
    lightChecker();
    if(ultrasonicSensor.getDist() > 80) {
      ultrasonicSensor.printDist();
      red.turnOff();
      yellow.turnOff();
      green.turnOn();
    }
    else if(ultrasonicSensor.getDist() <= 20) {
      ultrasonicSensor.printDist();
      green.turnOff();
      yellow.turnOff();
      red.turnOn();
    }
    else {
      ultrasonicSensor.printDist();
      red.turnOff();
      green.turnOff();
      yellow.turnOn();
    }
    delay(200);
  }
  red.turnOff();
  green.turnOff();
  yellow.turnOff();
  delay(500);
}