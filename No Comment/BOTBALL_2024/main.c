#include <kipr/wombat.h> 
void STEPPER_SERVO();
int main()
{
    int astro_servo=0;
    int solar_servo=1;
    int au; // set these value at school
    int ab;
    int su;
    int sb
    float speed=0.46;
    create3_connect();
    create3_wait();
    create3_rotate_degrees(-90, 45);
    create3_wait();
    create3_drive_straight(0.1, speed);
    create3_wait();
    STEPPER_SERVO(au, 20, ab);
    STEPPER_SERVO(au, 20, au);
    create3_drive_straight(1, speed); //change this distance
    create3_wait();
    create3_rotate_degrees(-90, 45);
    create3_wait();
    create3_drive_straight(0.5, 0.05); //prob change this dist
    create3_wait();
    int i=0;
    int angle=30;//change this angle
    while (i<10)
    {
        angle+=i*2;
        create3_rotate_degrees(angle, 10); //change this angle
        create3_wait();
        i+=1;
    }
    create3_rotate_degrees(90-angle, 20);
    create3_wait();
    create3_drive_straight(0.75, 0.05); //prob change this dist
    create3_wait();
    create3_rotate_degrees(90, 45);
    create3_wait();
    create3_drive_straight(0.75, 0.05); //prob change this dist
    create3_wait();
    create3_rotate_degrees(-90, 45);
    create3_wait();
    create3_drive_straight(0.5, 0.05); //prob change this dist
    create3_wait();
    create3_rotate_degrees(30, 10);
    create3_wait();
    create3_drive_straight(1, -speed);//change this dist at school
    create3_wait();
    return 0;
}
void STEPPER_SERVO(int port, int speed, int final)
{
    enable_servos();
    int pos=get_servo_position(port);
    if (pos>final)
    {
        while(pos>final)
        {
            set_servo_position(port, pos-speed);
            msleep(10);
            pos=get_servo_position(port);
        }
    }
    else
    {
        while(pos<final)
        {
            set_servo_position(port, pos+speed);
            msleep(10);
            pos=get_servo_position(port);
        }
    }
    set_servo_position(port, final);
    disable_servos();

}