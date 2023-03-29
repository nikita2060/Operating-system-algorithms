#include<stdio.h>
#include<stdbool.h>
//defining the no resources and processes
#define NO_OF_PROCESSES 5
#define NO_OF_RESOURCES 3
bool isSafeState[int safesequence[]];

int main()
{
    int available[NO_OF_RESOURCES];
    int max[NO_OF_PROCESSES][ NO_OF_RESOURCES];
    int allocation[NO_OF_PROCESSES][ NO_OF_RESOURCES];
    int need[NO_OF_PROCESSES][ NO_OF_RESOURCES];
    int safeSequence[NO_OF_PROCESSES];

    printf("Deadlock Avoidance using Bankers Algorithm\n");

    //input available instance for each resource and store it in each index of array named available
    for(int i = 0; i < NO_OF_RESOURCES; i++)
    {
        printf("\nEnter available instance of resource %d", i+1);
        scanf("%d",&available[i]);
    }

    //input need of each resource(A,B,C) for each process (0,1,2,3..)
    for(int i = 0; i < NO_OF_PROCESSES; i++)
    {
        printf("Enter  the maximum demand of resources required for process %d:\t", i);
        for(int j = 0; j < NO_OF_RESOURCES; j++)
        {
            scanf("%d",&max[i][j]);
        }

    }

    //input allocated resources for each process
    for(int i = 0; i < NO_OF_PROCESSES; i++)
    {
        printf("Enter  the number of resources required for process %d:\t", i);
        for(int j = 0; j < NO_OF_RESOURCES; j++)
        {
            scanf("%d",&allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }

    }

    //calculate need matrix
    for(int i = 0; i < NO_OF_PROCESSES; i++)
    {
        printf("\n\nRESULTS\n\nNEED MATRIX:");
        for(int j = 0; j < NO_OF_RESOURCES; j++)
        {
            printf("%d",need[i][j]);
            
        }
        printf("\n");

    }

bool isSafeState(int safesequence[])
{
    int work[NO_OF_PROCESSES],finish[NO_OF_PROCESSES];
    //initialize work and finish
    for(int i = 0;i < NO_OF_PROCESSES;i++)
    {
        work[i] = available[i];
        finish[i] = false;
    }
    for(int k =0; k<NO_OF_PROCESSES; k++)
    {
        for(int i=0; i< NO_OF_PROCESSES;i++)
        {
            if (!finish[i])
            {
                bool canExecute = true;
                for(int j = 0; j < NO_OF_RESOURCES;j++ )
                {
                    if(need[i][j]>work[j])
                    {
                        canExecute = false;
                        break;
                    }
                }
                if(canExecute)
                {
                    finish[i] = true;
                    for(int j =0;j<NO_OF_RESOURCES;j++)
                    {
                        work[j] +=allocation[i][j];
                    }
                    safesequence[k] = i;
                    break;
                }
            }
        }
        if (i==NO_OF_PROCESSES)
        { 
            break;
        }
    }
}
}



    



}

