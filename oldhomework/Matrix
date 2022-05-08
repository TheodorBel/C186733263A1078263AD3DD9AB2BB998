#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{

    char array[10] = {'1','2','3','4','5',' ',' ',' ',' ',' '};
    int k;
    int s = 0;
    for ( int c = 0; c < 10000000; c++)
    {
        k = rand() % 9;
        printf("%c", array[k]);
        usleep(80);
        s ++;
        if (s == 120)
        {
            printf("\n");
            s = 0;
        }
    }

}
