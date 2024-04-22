#include <kipr/wombat.h>
void SERVO_STEPPER(int port, int end, int speed);

int main()
{
    create_connect();
    double speed=0.46;
    int astro_servo=0;
    int solar_servo=1;
    int sd=400;
    int su=1600;
    int ad=900;
    int au=2040;
    create3_rotate_degrees(90.0, 45.0);
    create3_wait();
    create3_drive_straight(0.1, speed);
    create3_wait();
    SERVO_STEPPER(astro_servo, ad, 20);
    SERVO_STEPPER(astro_servo, au, 20);
        return 0;
}
void SERVO_STEPPER(int port, int end, int speed)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    if(end>pos)
    {
        while(pos<end)
        {
            set_servo_position(port, pos+speed);
            msleep(10);
            pos=get_servo_position(port);
        }
    }
    else
    {
        while(pos>end)
        {
            set_servo_position(port, pos-speed);
            msleep(10);
            pos=get_servo_position(port);
        } 
    }
}