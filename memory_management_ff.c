#include <stdio.h>
#define max 50

int main()
{
    int frag[max], b[max], p[max], i, j, numBlocks, numProces, temp;
    static int bf[max], ff[max];
    printf("\nMemory Allocation using First Fit\n");
    printf("\nEnter the number of memory blocks:");
    scanf("%d", &numBlocks);
    printf("Enter the number of processes to be accommodated:");
    scanf("%d", &numProces);

    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= numBlocks; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:\n");
    for(i = 1; i <= numProces; i++)
    {
        printf("Process %d:", i);
        scanf("%d", &p[i]);
    }

    for(i = 1; i <= numProces; i++)
    {
        for(j = 1; j <= numBlocks; j++)
        {
            if(bf[j] != 1)// bf[] = 0 means not allocated , =1 means allocated (ascertains if that specific block is occupied or not)
            {
                temp = b[j] - p[i];
                if(temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nProcess_no:\tProcess_size:\tBlock_no:\tBlock_size:\tFragment_Size");
    for(i = 1; i <= numProces; i++)
    {
        printf("\n%d\t\t%d\t\t", i, p[i]);
        if(ff[i] != 0)
        {
            printf("%d\t\t%d\t\t%d", ff[i], b[ff[i]], frag[i]);
        }
        else
        {
            printf("No Alloc\t No Alloc\t No Alloc");
        }
    }

    printf("\n");
    return 0;
}
