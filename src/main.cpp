#include <JetsonGPIO.h>
#include <iostream>
#include <pwm.h>

const int PWM = 10;
const int PIN1 = 9;
const int PIN2 = 11;

const int USED_PINS = 3;
int PINS[USED_PINS] = {10, 11, 9};

void cleanup() {
for (int i = 0; i < USED_PINS; i++)
{
    GPIO::cleanup(PINS[i]);
}
}

int main() {
 GPIO::setmode(GPIO::BCM);

// PWM p(test_pin, 255);
    GPIO::setup(PWM, GPIO::OUT, GPIO::HIGH);
    GPIO::setup(PIN1, GPIO::OUT, GPIO::HIGH);
    GPIO::setup(PIN2, GPIO::OUT, GPIO::LOW);

    //GPIO::output(18, GPIO::HIGH);

    std::cout << "we running" << std::endl;
    std::cin.get();

cleanup();
    return 0;
}
