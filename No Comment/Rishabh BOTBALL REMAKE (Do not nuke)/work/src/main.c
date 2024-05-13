#include <kipr/wombat.h>

int main()
{
    while(digital(0)==0)
    {
        motor(0,70);
        motor(2,70);
    }
    return 0;
}
