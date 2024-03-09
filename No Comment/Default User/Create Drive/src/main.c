#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    create3_drive_straight(0.5,0.25);
     create3_drive_straight(-0.5,0.25);
    create3_wait();
    
    return 0;
}
