#include <kipr/wombat.h>

int main()
{
    //down 1625 up 950 to 100
    enable_servos();
    int Servo = get_servo_position(1);
    while(Servo<1550)
    {
        set_servo_position(1,Servo);
        msleep(10);
        Servo = Servo + 10;
    }
    while(analog(2)<3000)
    {
        motor(0,-90);
        motor(3,-40);
    }
    while(analog(2)>3000)
    {
        motor(0,-40);
        motor(3,-90);
    }
    msleep(300);
    freeze(1);
    freeze(2);
    while(Servo>950)
    {
        motor(1,20);
        motor(2,20);
        set_servo_position(1,Servo);
        msleep(10);
        Servo = Servo + 10;
    }
    motor(1,-50);
    motor(2,-50);
    msleep(1000);
    while(Servo>100)
    {
        motor(1,-20);
        motor(2,-20);
        set_servo_position(1,Servo);
        msleep(10);
        Servo = Servo + 10;
    }
    return 0;
}
