#include <JetsonGPIO.h>
#include <pwm.h>
#include <chrono>

const int TIME_INTERVAL = 50; // PWM interval in microseconds

PWM::PWM(int pin, unsigned char value)
{
    GPIO::setup(pin, GPIO::OUT);
    setValue(value);
    thread = std::thread(&PWM::cycle, this);
}

PWM::~PWM()
{
    cycling = false;
    if (thread.joinable())
    {
        thread.join();
    }
}

void PWM::setValue(unsigned char value)
{
    this->value = value;
    duty = (TIME_INTERVAL * value) / 255;
}

void PWM::stop()
{
    this->~PWM();
}

void PWM::cycle()
{
    while (cycling)
    {
        GPIO::output(pin, GPIO::HIGH);
        std::this_thread::sleep_for(std::chrono::microseconds(duty));
        GPIO::output(pin, GPIO::LOW);
        std::this_thread::sleep_for(std::chrono::microseconds(TIME_INTERVAL - duty));
    }
}
