#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    int sides = 0;
    
    while (sides < 4){
    	create3_drive_straight(0.5, 10);
    	create3_rotate_degrees(90, 90);
        sides++;
    }
    
    return 0;
}
