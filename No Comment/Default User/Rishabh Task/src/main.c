#include <kipr/wombat.h>

int main()
{
    printf("Hello World\n");
    int sides=0;
    create3_connect();
    while(sides<4)
    {
        create3_drive_straight(0.5,0.5);
        create3_rotate_degrees(-90, 90);
        sides=sides+1;
    }
    return 0;
}
