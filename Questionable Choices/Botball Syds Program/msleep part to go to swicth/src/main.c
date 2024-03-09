#include <kipr/wombat.h>

int main()
{
    motor(1,90);
    motor(2,90);
    msleep(4000);
    
    motor(1,0);
    motor(2,90);
    msleep(1000);
    return 0;
}
