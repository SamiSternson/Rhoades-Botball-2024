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
    motor(rm, speed);
    motor(lm, -speed);
    msleep(400);
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
    while(analog(s)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    double start_time=seconds();
    while(seconds()-start_time<9)
    {
        if (analog(s)<thresh)
        {
            motor(rm, speed);
            motor(lm, 0);
        }
        else
        {
            motor(lm, speed);
            motor(rm, 0);
        }
    }
    while(analog(s)>thresh)
    {
        motor(rm, speed);
        motor(lm, 0);
    }
    motor(rm, speed);
    motor(lm, 0);
    msleep(500);
    motor(rm , speed);
    motor(lm, speed);
    msleep(1500);
    while(analog(s)<thresh)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while(analog(s)>thresh)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while(analog(s)<thresh)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while(analog(s)>thresh)
    {
        motor(rm, -speed);
        motor(lm, speed);
    }
    motor(rm, -speed/2);
    motor(lm,speed/2);
    msleep(1500);
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
    motor(lm, -speed/2);
    motor(rm, speed/2);
    msleep(1800);
    while(analog(s)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    motor(rm, speed);
    motor(lm, speed);
    msleep(2000);
    freeze(lm);
    freeze(rm);
    msleep(100);
    return 0;
}
