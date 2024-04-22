#include <kipr/wombat.h>
#include <stdint.h>
void LINE_FOLLOW_RIGHT_LEFT( int thresh, int speed, int t_c);
void LINE_FOLLOW_LEFT_LEFT(int thresh, int speed, int t_c);
void LINE_FOLLOW_RIGHT_RIGHT(int thresh, int speed, int t_c);
void LINE_FOLLOW_LEFT_RIGHT(int thresh, int speed, int t_c);
void LINE_FOLLOW_RIGHT_FLEFT( int thresh, int speed, int t_c);
void LINE_FOLLOW_LEFT_FLEFT(int thresh, int speed, int t_c);
void LINE_FOLLOW_RIGHT_FRIGHT(int thresh, int speed, int t_c);
void LINE_FOLLOW_LEFT_FRIGHT(int thresh, int speed, int t_c);
void LINE_FOLLOW_TWO(int thresh, int speed, int t_c);
void STEPPER_SERVO_DOWN(int port, int speed, int final);
void STEPPER_SERVO_UP(int port, int speed, int final);
void SUBF(int thresh, int speed);
void SUBB(int thresh, int speed);
void SUWF(int thresh, int speed);
void SUWB(int thresh, int speed);
void SCR();
void SCL();
void SCLF();
void SCRF();
int main()
{ 
    create_connect();
    int speed=200;
    int lwhite=SCL();
    int lfwhite=SCLF();
    int rfwhite=SCR();
    int rwhite=SCRF();
    while(get_create_lfcliff_amt()>lfwhite-300 || get_create_rfcliff_amt()>rfwhite-300)
    {
        create_drive_direct(speed, speed);
    }
    int lthresh=lwhite-(lwhite-SCL())/2;
    int lfthresh=lfwhite-(lfwhite-SCLF())/2;
    int rfthresh=rfwhite-(rfwhite-SCRF())/2;
    int rthresh=rwhite-(rwhite-SCR())/2;
    SUWF(lfthresh, speed/4)
    LINE_FOLLOW_RIGHT_FLEFT(lfthresh, speed, 0.2);
    create_disconnect();
    return 0;
}

void LINE_FOLLOW_RIGHT_LEFT(int thresh, int speed, int t_c)
{
    if (get_create_lcliff_amt()>thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_LEFT_LEFT(int thresh, int speed, int t_c)
{
    if (get_create_lcliff_amt()<thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_RIGHT_RIGHT(int thresh, int speed, int t_c)
{
    if (get_create_rcliff_amt()>thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_LEFT_RIGHT(int thresh, int speed, int t_c)
{
    if (get_create_rcliff_amt()<thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}
//
void LINE_FOLLOW_RIGHT_FLEFT(int thresh, int speed, int t_c)
{
    if (get_create_lfcliff_amt()>thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_LEFT_FLEFT(int thresh, int speed, int t_c)
{
    if (get_create_lfcliff_amt()<thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_RIGHT_FRIGHT(int thresh, int speed, int t_c)
{
    if (get_create_rfcliff_amt()>thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_LEFT_FRIGHT(int thresh, int speed, int t_c)
{
    if (get_create_rfcliff_amt()<thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else
    {
       create_drive_direct(speed, speed*t_c); 
    }
}

void LINE_FOLLOW_TWO(int thresh, int speed, int t_c)
{
    if (get_create_lfcliff_amt()>thresh && get_create_rfcliff_amt()>thresh)
    {
        create_drive_direct(speed, speed);
    }
    else if (get_create_lfcliff_amt()<thresh && get_create_rfcliff_amt()>thresh)
    {
        create_drive_direct(speed*t_c, speed);
    }
    else if (get_create_lfcliff_amt()>thresh && get_create_rfcliff_amt()<thresh)
    {
        create_drive_direct(speed, speed*t_c);
    }
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
void SUBF(int thresh, int speed)
{
    while(get_create_lfcliff_amt()>thresh || get_create_rfcliff_amt()>thresh)
    {
        if (get_create_lfcliff_amt()>thresh && get_create_rfcliff_amt()>thresh)
        {
            create_drive_direct(speed, speed);
        }
        else if (get_create_lfcliff_amt()<thresh && get_create_rfcliff_amt()>thresh)
        {
            create_drive_direct(-speed, speed);
        }
        else if (get_create_lfcliff_amt()>thresh && get_create_rfcliff_amt()<thresh)
        {
            create_drive_direct(speed, -speed);
        }
        else
        {
            create_drive_direct(0, 0);
        }
    }
}
void SUBB(int thresh, int speed)
{
    while(get_create_lcliff_amt()>thresh || get_create_rcliff_amt()>thresh)
    {
        if (get_create_lcliff_amt()>thresh && get_create_rcliff_amt()>thresh)
        {
            create_drive_direct(speed, speed);
        }
        else if (get_create_lcliff_amt()<thresh && get_create_rcliff_amt()>thresh)
        {
            create_drive_direct(-speed, speed);
        }
        else if (get_create_lcliff_amt()>thresh && get_create_rcliff_amt()<thresh)
        {
            create_drive_direct(speed, -speed);
        }
        else
        {
            create_drive_direct(0, 0);
        }
    }
}
void SUWF(int thresh, int speed)
{
    while(get_create_lfcliff_amt()<thresh || get_create_rfcliff_amt()<thresh)
    {
        if (get_create_lfcliff_amt()<thresh && get_create_rfcliff_amt()<thresh)
        {
            create_drive_direct(speed, speed);
        }
        else if (get_create_lfcliff_amt()>thresh && get_create_rfcliff_amt()<thresh)
        {
            create_drive_direct(-speed, speed);
        }
        else if (get_create_lfcliff_amt()<thresh && get_create_rfcliff_amt()>thresh)
        {
            create_drive_direct(speed, -speed);
        }
        else
        {
            create_drive_direct(0, 0);
        }
    }
}
void SUWB(int thresh, int speed)
{
    while(get_create_lcliff_amt()<thresh || get_create_rcliff_amt()<thresh)
    {
        if (get_create_lcliff_amt()<thresh && get_create_rcliff_amt()<thresh)
        {
            create_drive_direct(speed, speed);
        }
        else if (get_create_lcliff_amt()<thresh && get_create_rcliff_amt()>thresh)
        {
            create_drive_direct(-speed, speed);
        }
        else if (get_create_lcliff_amt()<thresh && get_create_rcliff_amt()>thresh)
        {
            create_drive_direct(speed, -speed);
        }
        else
        {
            create_drive_direct(0, 0);
        }
    }
}

void SCR()
{
    int i=0;
    int num=0;
    while (i<50)
    {
        num+=get_create_rcliff_amt();
        i+=1;
    }
    int avg=num/50;
    return avg
}
void SCL()
{
    int i=0;
    int num=0;
    while (i<50)
    {
        num+=get_create_lcliff_amt();
        i+=1;
    }
    int avg=num/50;
    return avg
}
void SCRF()
{
    int i=0;
    int num=0;
    while (i<50)
    {
        num+=get_create_rfcliff_amt();
        i+=1;
    }
    int avg=num/50;
    return avg
}
void SCLF()
{
    int i=0;
    int num=0;
    while (i<50)
    {
        num+=get_create_lfcliff_amt();
        i+=1;
    }
    int avg=num/50;
    return avg
}