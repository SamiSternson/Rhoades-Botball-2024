#include <kipr/wombat.h>
void servo(int port, float targetangle, float time);

int main()
{
    msleep(100);
    servo(0, 1500, 2);
    servo(0, 5, 2);
    servo(0, 1500, 2);
    motor(0,80);
    motor(2,80);
    msleep(2000);
    while(analog(0)<2000)
    {
        motor(0,80);
        motor(2,80);
    }
    motor(0,-75);
    motor(2,-75);
    msleep(500);
    motor(0,75);
    motor(2,0);
    msleep(500);
    while(analog(0)<2000)
    {
        motor(0,80);
        motor(2,80);
    }
    motor(0,80);
    motor(2,80);
    msleep(500);
    motor(0,0);
    motor(2,75);
    msleep(500);
    motor(0,0);
    motor(2,75);
    msleep(1000);
    motor(0,0);
    motor(2,0);
    msleep(50);
    servo(0, 5, 3);
    motor(0,0);
    motor(2,75);
    msleep(1000);
    while(digital(0)==0)   //drive forwaard while you don't touch station.
    {
        motor(0,30);
        motor(3,30);
    }
    motor(0,-15);
    motor(2,-15);
    msleep(100);
    servo(0, 1500, 2);
    motor(0, 0);
    motor(2,15);
    msleep(500);
    return 0;
}
void servo(int port, float targetangle, float time)
{
    float currentangle = get_servo_position(port);
    float angledistance;
    float repeats;
    int repeated = 0;

    if (currentangle < targetangle) {
        angledistance = targetangle - currentangle;
        repeats = angledistance / 1;
    }
    else if (currentangle > targetangle) {
        angledistance = currentangle - targetangle;
        repeats = angledistance / 1;
    }

    //time = angledistance * time;

    float sleeptime = (time * 1000) / repeats;


    enable_servo(port);
    while (currentangle < targetangle) {
        currentangle = currentangle + 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    while (currentangle > targetangle) 
    {
        currentangle = currentangle - 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    disable_servo(port);
}
