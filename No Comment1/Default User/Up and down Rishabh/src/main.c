#include <kipr/wombat.h>

int main()
{
    printf("Hello World\n");
    //250 for Ahran 0 for Dylan
    enable_servos();
    create3_connect();
    int Servo = get_servo_position(3);
     while(Servo<1900)
    {    
        Servo=Servo+10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo>0)
    {
        Servo=Servo-10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo<1900)
    {    
        Servo=Servo+10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo>0)
    {
        Servo=Servo-10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo<1900)
    {    
        Servo=Servo+10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    disable_servos();
    //1900 high and 250 low
    return 0;
}
