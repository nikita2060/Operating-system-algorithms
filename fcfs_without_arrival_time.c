#include<stdio.h>

int main()
{
    int no_of_processes;
    printf("Enter number of processes\n");
    scanf("%d", &no_of_processes);
    int burst_time[no_of_processes], waiting_time[no_of_processes],  turn_around_time[no_of_processes];
    int total_waiting_time, total_turn_around_time;
    //input burst time from user
    printf("Enter burst time for the given processes:\n");
    for(int i = 0; i < no_of_processes; i++)
    {

        printf("Process %d : ",i+1);
        scanf("%d", &burst_time[i]);

    }

    
    //calculate waiting time
    waiting_time[0] = 0;
    for(int i = 1; i < no_of_processes; i++)
    {

        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        total_waiting_time += waiting_time[i];


    }

    for(int i = 0; i < no_of_processes; i++)
    {

        turn_around_time[i] = waiting_time[i] + burst_time[i];
        total_turn_around_time += turn_around_time[i];

    }

    //printing executable table
    printf("_________________________________________________________\n");
    printf("| SN   | Burst time  | Waiting time  | Turn around time |\n");
    printf("---------------------------------------------------------\n");


    for(int i = 0; i < no_of_processes; i++)
    {
   
        printf("|  %d   |    %d         |       %d      |         %d        |\n", i+1, burst_time[i], waiting_time[i], turn_around_time[i]);

    }
    printf("---------------------------------------------------------\n");

    //Gantt chart
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("+--------");

    }
    printf("\n");
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("|  P%d    ", i+1);
    }
    printf("\n");
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("+--------");

    }
    printf("\n");
    printf("0        ");
    for(int i = 0; i < no_of_processes; i++)
    {
        printf("%d        ",turn_around_time[i]);
    }

    float avg_waiting_time = (total_waiting_time / no_of_processes);
    float avg_total_turn_around_time = (total_turn_around_time / no_of_processes);

    printf("\n\nAverage waiting time : %d ", avg_waiting_time);
    printf("\nAverage turn around  time : %d\n", avg_total_turn_around_time );



}