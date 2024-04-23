#include <kipr/wombat.h>

int main()
{
    int STEP=1000;  //intialize your servo stepper to the top position????
    enable_servos();
    set_servo_position(0,1500);
    msleep(200);
    disable_servos(); 

    motor(2,50);
    motor(0,50);
    msleep(1000);

    motor(2,50);
    motor(0,0);
    msleep(400);
    ao();

    enable_servos();
    while(STEP > 300)
    {
        set_servo_position(0,STEP);
        msleep(50);
        STEP=STEP-10;
    }
    disable_servos();

    motor(0,50);
    motor(2,20);
    msleep(1000);

    motor(0,70);
    motor(2,40);
    msleep(300);

    while(digital(0)==0)   //drive forwaard while you don't touch station.
    {
        motor(0,30);
        motor(2,30);
    }
    return 0;
}
