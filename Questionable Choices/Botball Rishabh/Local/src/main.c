#include <kipr/wombat.h>
int LOCO()
{
    while(analog(1)<3000||analog(0)<3000)
    {
        if((analog(1)<3000)&&(analog(0)>3000))
        {
            motor(1,45);
            motor(2,90);
        }
        else if((analog(1)>3000)&&(analog(0)<3000))
        {
            motor(1,90);
            motor(2,45);
        }
        else
        {
            motor(1,90);
            motor(2,90);
        }
    }
    return 0;
}

int main()
{
LOCO();
    return 0;
}
