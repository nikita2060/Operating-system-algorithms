#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    for(int i = 0; i < 3; i++)
    {
        int random = rand() % 3 ;
        printf(" %d\t ", random);
    }
}


