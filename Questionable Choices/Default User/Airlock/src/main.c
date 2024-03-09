#include <kipr/wombat.h>

int main()
{

    motor(1,75);
    motor(2,75);
    msleep(3000);

    motor(1,75);
    motor(2,0);
    msleep(2000);

    motor(1,75);
    motor(2,50);
    msleep(3000);
    
    motor(1,-75);
    motor(2,-75);
    msleep(3000);
    return 0;
}
