#include <kipr/wombat.h>

int main()
{
    int active = 1;
    char input[] = "N/A";
    while (active == 1) {
    	scanf("%s", input);
    	printf("\n%s\n", input);
    	//int length = sizeof(input) / sizeof(input[0]);
    	//if (input[length] == "."){active = 0;}
    }
    return 0;
}
