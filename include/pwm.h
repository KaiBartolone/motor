#include <thread>

class PWM
{
private:
    int pin;
    unsigned char value;
    int duty;
    bool cycling = true;
    std::thread thread;

public:
    PWM(int pin, unsigned char value);
    ~PWM();
    void stop();
    void setValue(unsigned char value);

private:
    void cycle();
};
