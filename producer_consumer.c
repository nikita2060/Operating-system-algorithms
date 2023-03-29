#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void producer();
void consumer();

int flag = 1;
int no_of_full_slots = 0;
int no_of_empty_slots = 10;
int current_item = 0;

int main()
{
    int choice;
    printf("Enter your choice\n");
    printf("1.Call producer\n");
    printf("2.Call consumer\n");
    printf("3.Exit\n");
    scanf("%d",&choice);
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    int random = rand() % 3;
    while(random == 0)
    {
        random = rand() % 3;
    }
    #pragma omp critical
    switch(choice)
    {
        case 1:
        if ( no_of_full_slots != 10 && flag == 1)
        {
            producer();
            break;
        }
        else
            printf("Buffer is full\n");
            break;

        

        case 2:
        if ( no_of_empty_slots =! 10 && flag == 1)
        {
            consumer();
            break;
        }
        else
        printf("Buffer is empty\n");
        break;
        

        case 3:
        exit(0);
        break;

    }


   

    

}
void producer()
{
    flag-- ;
    no_of_full_slots++;
    no_of_empty_slots--;
    current_item++;
    flag++;
    printf("Producer produces item %d ",current_item);
}

void consumer()
{
    flag-- ;
    no_of_full_slots--;
    no_of_empty_slots++;
    current_item--;
    flag++;
    printf("Consumer consumes item %d",current_item);

}
