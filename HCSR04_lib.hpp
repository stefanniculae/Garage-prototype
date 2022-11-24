#ifndef HCSR04_LIB_HPP
#define HCSR04_LIB_HPP

#include <Arduino.h>

class HCSR04{
private:
        int trig;
        int echo;
public:
        HCSR04();
        HCSR04(const int, const int);
        ~HCSR04();
        void setPins(const int, const int);
        float getDist();
        void printDist();
};

#endif
