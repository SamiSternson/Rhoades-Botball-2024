#include <kipr/wombat.h>

int main()
{
    int rm=0;
    int lm=1;
    double speed=90;
    double start_time=seconds();
    while(seconds()-start_time<10)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    return 0;
}
