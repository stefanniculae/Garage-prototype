#ifndef DHT11_LIB_HPP
#define DHT11_LIB_HPP

#include <Arduino.h>

class DHT11 {
private:
        int pin;
        uint8_t data[5];
        unsigned long lastReadTime;
        float lastTemperatureRead;
        float lastHumidityRead;
public:
        DHT11();
        DHT11(const int);
        ~DHT11();
        void setPin(const int);
        float getTemperatureCelsius();
        float getTemperatureFahrenheit();
        float getHumidity();
        uint8_t readData();
        uint32_t expectPulse(bool);
        void getInformations();
};

#endif
