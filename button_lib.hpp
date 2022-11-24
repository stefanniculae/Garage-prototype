#ifndef BUTTON_LIB_HPP
#define BUTTON_LIB_HPP

#include <Arduino.h>

class Button {
private: 
        int pin;
        bool state;
public:
        Button();
        Button(const int);
        ~Button();
        void setPin(const int);
        bool getState();
};

#endif