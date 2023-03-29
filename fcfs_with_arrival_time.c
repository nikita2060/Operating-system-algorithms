#include<stdio.h>

int main()
{
    int no_of_processes;
    printf("Enter number of processes\n");
    scanf("%d",&no_of_processes);
    int burst_time[no_of_processes], arrival_time[no_of_processes], waiting_time[no_of_processes], completion_time[no_of_processes], turn_around_time[no_of_processes];
    int total_waiting_time, total_turn_around_time;
    float average_waiting_time, average_turn_around_time;

    //input burst time and arrival time

    for(int i = 0; i < no_of_processes; i++)
    {
        printf("Process %d: ", i+1);
        printf("Arrival time :");
        scanf("%d", &arrival_time[i]);
        printf("Burst time :");
        scanf("%d", &burst_time[i]);

    }

    
    //calculate completion time
    completion_time[0] = burst_time[0];

    for(int i = 1; i < no_of_processes; i++)
    {
        if( arrival_time[i] > completion_time[i-1])
        {
            completion_time[i] = arrival_time[i] + burst_time[i];
        }
        else
        {
            completion_time[i] = completion_time[i-1] + burst_time[i];

        }

    }

    //calculate waiting time
    waiting_time[0] = 0;
    for(int i = 1; i < no_of_processes; i++)
    {
        waiting_time[i] = completion_time[i] - arrival_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
    }

    //calculate turn around time
    for(int i = 0; i < no_of_processes; i++)
    {
        turn_around_time[i] = waiting_time[i] + burst_time[i];
        total_turn_around_time += turn_around_time[i];
    }

    //calculate average waiting time and turn around time

    average_turn_around_time = total_turn_around_time / no_of_processes;
    average_waiting_time = total_waiting_time / no_of_processes;

    //execution table
    printf("Printing Execution table\n");
    printf("+---------+-----------------------+------------------------+----------------------------+----------------------------+\n");
    printf("|   S.N.  |     Arrival time      |      Burst time        |       Waiting time         |    Turn around time        |\n ");
    printf("+---------+-----------------------+------------------------+----------------------------+----------------------------+\n");

    for(int i = 0; i < no_of_processes; i++)
    { 
        printf("|     %d     |            %d           |         %d             |            %d              |          %d                |\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turn_around_time[i]);
        printf("+---------+-----------------------+------------------------+----------------------------+----------------------------+\n");

    }
    
    //Gantt chart
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("+-----");
    }
    printf("\n");
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("|  P%d  ", i+1 );
    }
    printf("\n");
    printf("0      ");
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("%d     ",completion_time[i]);
    }
    











}