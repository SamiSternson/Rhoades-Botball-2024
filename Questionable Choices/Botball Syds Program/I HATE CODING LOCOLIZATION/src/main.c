#include <kipr/wombat.h>

int LOCO()

    int main()
{
    LOCO()
        motor(1,90);
    motor(2,90);
    msleep(2000);

        return 0;
}
int LOCO()
{
    while(analog(0)<3100||analog(1)<3100)
    {
        if(analog(0)>3200 &&  analog(1)<3100)    // when analog 0 sees the black tape, turn on motor 2
        {
            motor(1,0);
            motor(2,80);
        }
        else if(analog(0)<3100 && analog(1)>3200) // when analog 0 doesn't see the black, turn on motor 1
        {
            motor(1,80);
            motor(2,0);
        }
        else          //if neither analogs see the black, go strait
        {
            motor(1,100);
            motor(2,100);
        }
    }
}
