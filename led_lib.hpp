#ifndef LED_LIB_HPP
#define LED_LIB_HPP

#include <Arduino.h>

class Led {
private: 
        int pin;
        bool state;
public:
        Led();
        Led(const int);
        ~Led();
        void setPin(const int);
        bool getState();
        void turnOn();
        void turnOff();
};

#endif