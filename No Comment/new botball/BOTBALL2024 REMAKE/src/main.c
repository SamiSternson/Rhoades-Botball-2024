#include <kipr/wombat.h>

int main()
{
    wait_for_light(5);
    shut_down_in(119);
    msleep(10000);
    int POMS=0;
    int thresh=2000;
    motor(0, 100);
    motor(2, 100);
    msleep(2000);
    //line follows
    while (POMS<2000)
    {
        if (analog(0)<2500)
        {
        motor(0, 50);
        motor(2, 0);
        }
        else
        {
            motor(0, 0);
            motor(2, 50);
        }
        POMS=POMS+1;
    }
    motor(0, -100);
    motor(2, 0);
    msleep(1000);
    //dependent upon QC getting the astronauts
    while (analog(0)<2000)
    {
        motor(0, 50);
        motor(2, 0);
    }
    POMS=0;//reinitialize value
    while (POMS<3000)
    {
        if (analog(0)<2500)
        {
        motor(0, 50);
        motor(2, 0);
        }
        else
        {
            motor(0, 0);
            motor(2, 50);
        }
        POMS=POMS+1;
    }
    motor(0, 100);
    motor(2, 100);
    msleep(900);
    while (analog(0)<2000)
    {
        motor(0, 50);
        motor(2, 0);
    }
    
    while (analog(0)>2000)
    {
        motor(0, 50);
        motor(2, 0);
    }
    motor(0, 50);
    motor(2, 0);
    msleep(500);
    
    motor(0, 100);
    motor(2, 100);
    msleep(500);
    
    motor(0, -100);
    motor(2, 0);
    msleep(300);
    POMS=0;
    while (POMS<10500)
    {
        if (analog(0)>2500)
        {
        motor(0, 0);
        motor(2, 50);
        }
        else
        {
            motor(0, 50);
            motor(2, 0);
        }
        POMS=POMS+1;
    }
    while(analog(0)<thresh)
    {
     motor(0, 50);
        motor(2, 0);
    }
    while(analog(0)>thresh)
    {
     motor(0, 50);
        motor(2, 0);
    }
    motor(0, 50);
    motor(2, 00);
    msleep(1500);
    motor(0, 50);
    motor(2, 50);
    msleep(1000);
    
    return 0;
}
