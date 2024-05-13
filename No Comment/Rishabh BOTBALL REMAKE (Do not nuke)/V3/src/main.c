#include <kipr/wombat.h>
void SSU(int port, int speed, int final);
void SSD(int port, int speed, int final);
void servo(int port, int time, int finalpos);
int main()
{
    msleep(100);
    /*wait_for_light(1);
    shut_down_in(119);*/
    servo(3, 2000, 1070);
    servo(0, 2000, 2047);// raise astro grabber
    motor(0,0);// freeze motors
    motor(2,0);
    servo(0, 2000, 800);// lower astro grabber
    servo(0, 2000, 2047);// raise astro grabber
    motor(0,87);
    motor(2,85);
    msleep(300);
    while(analog(0)<2500)
    {
        motor(0,72);
        motor(2,70);
    }
    double start_time = seconds();
    while(seconds() - start_time < 3)
    {
        while(digital(1)==0)
        {
            motor(0,37);
            motor(2,70);
        }
        if(digital(1)==1)
        {
            motor(0,72);
            motor(2,35);
            msleep(500);
        }
    }
    while(analog(0)<1700)
    {
        motor(0,72);
        motor(2,70);
    }
    freeze(0);
    freeze(2);
    msleep(100);

    while(digital(1)==0)
    {
        motor(0,40);
        motor(2,42);
    }
    /*motor(0,30);
    motor(2,0);
    msleep(100);*/
    freeze(0);
    freeze(2);
    msleep(100);
    servo(0, 2000, 1500);
    while(digital(0)==0)
    {
        motor(0,32);
        motor(2,30);
    }
    motor(0,-20);
    motor(2,-20);
    msleep(800);
    freeze(0);
    freeze(2);
    msleep(100);
    servo(0, 2000, 2047);
    motor(0,0);
    motor(2,20);
    msleep(1200);
    freeze(0);
    freeze(2);
    msleep(100);
    servo(0, 2000, 1600);
    freeze(0);
    freeze(2);
    msleep(100);
    int POMS = 0;
    while(POMS < 8)
    {
        motor(0,50);
        motor(2,50);
        msleep(400);
        motor(0,-50);
        motor(2,-50);
        msleep(400);
        motor(0,50);
        motor(2,50);
        msleep(400);
        motor(0,-50);
        motor(2,-50);
        msleep(400);
        POMS = POMS + 1;
    }
    while(digital(1)==0)
    {
        motor(0,30);
        motor(2,30);
    }
    motor(0,0);
    motor(2,100);       // lower claw to scoop the poms
    msleep(100);
    freeze(0);
    freeze(2);
    servo(3, 2000, 1990);
    motor(0,-100);
    motor(2,-100);
    msleep(1500);
    freeze(0);
    freeze(2);
    enable_servos();
    {
        set_servo_position(3,1100);
    }
    disable_servos();
    
    
    motor(0,100);
    motor(2,100);
    msleep(1000);
    freeze(0);
    freeze(2);
    
    
    servo(3, 2000, 1990);
    motor(0,-100);
    motor(2,-100);
    msleep(2000);
    return 0;
}
void servo(int port, int time, int finalpos)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    int round = 0;
    int time2drop = 0;
    if(pos<finalpos)
    {
        round = finalpos-pos;
        time2drop = time/round;
        while(pos<finalpos)
        {
            set_servo_position(port, pos);
            msleep(time2drop);
            pos = pos + 1;
        }
    }
    if(pos>finalpos)
    {
        round = pos - finalpos;
        time2drop = time/round;
        while(pos>finalpos)
        {
            set_servo_position(port, pos);
            msleep(time2drop);
            pos=pos-1;
        }
    }
    disable_servo(port);
}
void SSU(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos<final)
    {
        pos+=10;
        set_servo_position(port, pos);
        msleep(20);
    }
    disable_servo(port);
}
void SSD(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos>final)
    {
        pos-=10;
        set_servo_position(port, pos);
        msleep(20);
    }
    disable_servo(port);
}