#include <kipr/wombat.h>

int main()
{
    int rm=0;
    int lm=2;
    int thresh=2000;
    int s=0;
    int speed=90;
    wait_for_light(5);
    shut_down_in(119);
    msleep(25000);
    while(analog(s)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    while(analog(s)>thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    while(analog(s)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    while(analog(s)>thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    motor(rm, speed);
    motor(lm, speed);
    msleep(500);
    double start_time=seconds();
    while(seconds()-start_time<5)
    {
        if (analog(s)<thresh)
        {
            motor(rm, 0);
            motor(lm, speed);
        }
        else 
        {
            motor(lm, 0);
            motor(rm, speed);
        }
    }
    motor(rm, speed);
    motor(lm, -speed);
    msleep(700);
    while(analog(s)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    motor(rm, speed);
    motor(lm, speed);
    msleep(2000);
    freeze(rm);
    freeze(lm);
    return 0;
}
