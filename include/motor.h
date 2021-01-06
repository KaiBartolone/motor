#include <pwm.h>

class Motor
{
private:
    int pin1, pin2, pwm;
    PWM controller;

public:
    Motor(int pin1, int pin2, int pwm);
    ~Motor();

    void setAngularVelocity(int velocity);
    void setAngularPosition(int delta, int maxVelocity);
};