#include "DHT11_lib.hpp"

#define MIN_INTERVAL 1300 
#define TIMEOUT UINT32_MAX

DHT11::DHT11() {
  lastReadTime = 0;
  lastTemperatureRead = NAN;
  lastHumidityRead = NAN;
}

DHT11::DHT11(const int p) {
  this->pin = p;
  pinMode(pin, INPUT_PULLUP);
}

DHT11::~DHT11() {

}

//method to set the pin for the sensor
void DHT11::setPin(const int p) {
  pin = p;
  pinMode(pin, INPUT_PULLUP);
}

void DHT11::getInformations() {
  if(millis() - lastReadTime < MIN_INTERVAL) {
    return;
  }
  float t = NAN;
  float h = NAN;
  if(readData()){
    t = data[2];
    t = t + data[3] * 0.1;
    lastTemperatureRead = t;
    h = data[0];
    h = h + data[1] * 0.1;
    lastHumidityRead = h;
    lastReadTime = millis();
  }
}

//determinates the temperature in celsius
float DHT11::getTemperatureCelsius() {
  getInformations();
  return lastTemperatureRead;
}
//determinates the temperature in fahrenheit
float DHT11::getTemperatureFahrenheit() {
  return (getTemperatureCelsius() * 1.8 + 32);
}

//determinates the humidity
float DHT11::getHumidity() {
  getInformations();
  return lastHumidityRead;
}

uint8_t DHT11::readData() {
  //reset of the data vector to zero for all the bits
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;
  //go into high impedence state to let pull-up raise data line level and
  //start the reading process
  pinMode(pin, INPUT_PULLUP);
  delay(1);  

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);

  //minimum delay from the datasheet
  delay(20); 

  uint32_t cycles[80];

  //delay to let sensor pull data line low
  pinMode(pin, INPUT_PULLUP);
  delayMicroseconds(55);

  //first expect a low signal for ~80 microseconds followed by a high signal
  uint32_t ls = expectPulse(LOW);
  uint32_t hs = expectPulse(HIGH);

  //the read of the 40 bits from the sensor
  for (int i = 0; i < 80; i += 2) {
    cycles[i] = expectPulse(LOW);
    cycles[i + 1] = expectPulse(HIGH);
  }

  //determinates is the bits are 0 or 1 and forms the data vector with information
  for (int i = 0; i < 40; ++i) {
    uint32_t lowCycles = cycles[2 * i];
    uint32_t highCycles = cycles[2 * i + 1];

    data[i / 8] <<= 1;
    if (highCycles > lowCycles) {
      data[i / 8] |= 1;
    }
  }
}

//determinates the length of a pulse
uint32_t DHT11::expectPulse(bool level) {
  uint32_t count = 0;
  while (digitalRead(pin) == level) {
    count++;
  }
  return count;
}