#ifndef RELAY_LIB_HPP
#define RELAY_LIB_HPP

#include <Arduino.h>

class Relay {
private: 
        int pin;
        bool state;
        bool normallyOpen;
public:
        Relay();
        Relay(const int, const bool);
        ~Relay();
        void setRelay(const int, const bool);
        bool getState();
        void turnOn();
        void turnOff();
};

#endif
