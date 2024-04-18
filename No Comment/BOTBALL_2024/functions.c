#include <kipr/wombat.h>
#include <stdint.h>
void SUB(int s1, int s2, int t1, int t2, float speed, float angular_speed);
int SC(int port);
void STEPPER_SERVO_DOWN(int port, int speed, int final);
void STEPPER_SERVO_UP(int port, int speed, int final);

int main()
{
    int astro_servo=0;
    int solar_servo=1;
    int au=2047;
    int ad=525;
    int su=2047;
    int sd=700;
    float speed=0.46;
    int far_thresh;//set this value at school
    int t1;
    int t2;
    int i=0;
    create3_connect();
    create3_wait();
    create3_rotate_degrees(-90, 45);
    create3_wait();
    SUB(1, 2, t1, t2, speed/2, 10);
    create3_drive_straight(0.15, speed);//change this dist later
    create3_wait();
    STEPPER_SERVO_DOWN(astro_servo, 10, ad);
    STEPPER_SERVO_UP(astro_servo, 20, au);
    while(create3_sensor_ir>far_thresh)
    {
        create3_follow_wall(Create3FollowRight, 0.001);
        if (create3_sensor_ir<far_thresh)
        {
            create3_velocity_set_components(0, 0);
            create3_wait();
        }
    }
    create3_rotate_degrees(-5, 10); //change this angle later
    STEPPER_SERVO_DOWN(astro_servo, 10, ad);
    create3_drive_straight(-0.005, -0.1);
    create3_wait();
    STEPPER_SERVO_UP(astro_servo, 20, au);
    create3_drive_straight(0.01, 0.1);
    create3_wait();
    while(i<10)
    {
        create3_rotate_degrees(-1, 10); //change this angle later
        create3_wait();
        i+=1;
    }
    create3_rotate_degrees(100, 45);
    create3_wait();
    SUB(1, 2, t1, t2, speed/2, 10);
    create3_drive_straight(0.15, speed);
    create3_wait();
    SUB(1, 2, t1, t2, speed/2, 10);
    while(create3_sensor_bump(1)==0 && create3_sensor_bump(2)==0 )
    {
        create3_velocity_set_components(0.001, speed);
        if (create3_sensor_bump(1)==1 || create3_sensor_bump(2)==1 )
        {
            create3_velocity_set_components(0, 0);
            create3_wait();
        }
    }
    create3_rotate_degrees(20, 20);
    create3_wait();
    create3_drive_straight(-0.5, -speed);
    create3_wait();
    create3_rotate_degrees(-20, 20);
    create3_wait();
    create3_drive_straight(-1, -speed);
    create3_wait();
    create3_rotate_degrees(-90, 45);
    create3_wait();
    while(create3_sensor_bump(1)==0 && create3_sensor_bump(2)==0 )
    {
        create3_velocity_set_components(0.001, speed);
        if (create3_sensor_bump(1)==1 || create3_sensor_bump(2)==1 )
        {
            create3_velocity_set_components(0, 0);
            create3_wait();
        }
    }
    create3_rotate_degrees(-90, 45);
    create3_wait();
    while(create3_sensor_bump(1)==0 && create3_sensor_bump(2)==0 )
        {
            create3_velocity_set_components(0.001, speed);
            if (create3_sensor_bump(1)==1 || create3_sensor_bump(2)==1 )
            {
                create3_velocity_set_components(0, 0);
                create3_wait();
            }
        }
    create3_wait();
    return 0;
}
void SUB(int s1, int s2, int t1, int t2, float speed, float angular_speed)
{
    while (create3_sensor_cliff(s1)>t1 || create3_sensor_cliff(s2)>t2)
    {
        if (create3_sensor_cliff(s1)>t1 && create3_sensor_cliff(s2)>t2)
        {
            create3_velocity_set_components(speed, 0);
            if (create3_sensor_cliff(s1)<t1 || create3_sensor_cliff(s2)<t2)
            {
                create3_velocity_set_components(0, 0);
                create3_wait();
            }
        }
        else if (create3_sensor_cliff(s1)<t1 && create3_sensor_cliff(s2)>t2)
        {
            create3_rotate_degrees(1, angular_speed);
            if (create3_sensor_cliff(s2)<t2)
            {
                create3_rotate_degrees(0, 0);
                create3_wait();
            }
            
        }
        else if (create3_sensor_cliff(s1)>t1 && create3_sensor_cliff(s2)<t2)
        {
            create3_rotate_degrees(-1, angular_speed);
            if (create3_sensor_cliff(s1)<t1)
            {
                create3_rotate_degrees(0, 0);
                create3_wait();
            }
            
        }
        else
        {
            create3_velocity_set_components(0, 0);
            create3_wait();
        }

    }
}
int SC(int port)
{
    int i=0;
    int num=0;
    while(i<50)
    {
        num+=create3_sensor_cliff(port);
        i+=1;
    }
    int avg=num/50
    return avg;
}

void STEPPER_SERVO_DOWN(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos>final)
    {
        pos-=speed
        set_servo_position(port, pos);
        msleep(10);
    }
    set_servo_position(port, final);
    msleep(10);
}

void STEPPER_SERVO_UP(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos<final)
    {
        pos+=speed
        set_servo_position(port, pos);
        msleep(10);
    }
    set_servo_position(port, final);
    msleep(10);
}