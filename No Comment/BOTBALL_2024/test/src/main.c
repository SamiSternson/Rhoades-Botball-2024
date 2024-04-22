#include <kipr/wombat.h>
int SC(int port);
int main()
{
    printf("%d", SC(0));
    return 0;
}

int SC(int port)
{
    int i=0;
    int num=0;
    while(i<50)
    {
        num+=create3_sensor_cliff(port);
        printf("%d\n", create3_sensor_cliff(port));
        i+=1;
    }
    int avg=num/50;
    return avg;
}
