#include <kipr/wombat.h>

int main()
{
    create3_connect();
    enable_servos();
    int Servo = get_servo_position(3);
    while(Servo<1900)
    {    
        Servo=Servo+10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo>250)
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
    while(Servo>250)
    {
        Servo=Servo-10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    #include <kipr/wombat.h>    

    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);   
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_rotate_degrees(2,45);
    disable_servos();
    create3_wait();
    return 0;
}
