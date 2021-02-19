#include <stdio.h>
#include <string.h> // memmove

int main(void)
{
    int queue[10] = {0,};
    for(;;)
    {
        int command;
        printf("add(1), pop(2), display(3), quit(4): ");
        scanf("%d",&command);
        
        switch(command)
        {
            case 1: //add
                {
                    int sequence = -1;
                    for(int i=0; i<10; i++)
                    {
                        if(queue[i] == 0)
                        {
                            sequence = i;
                            break;
                        }
                    }
                    if(sequence == -1)
                    {
                        printf("full\n");
                        break;
                    }
                    else
                    {
                        printf("number: ");
                        scanf("%d",&queue[sequence]);
                        break;
                    }
                }
            case 2: //pop
                printf("pop: %d\n",queue[0]);
                memmove(queue, queue+1, sizeof(int)*9);
                queue[9] = 0;
                break;
            case 3: //display
                if(queue[0] == 0)
                {
                    printf("empty\n");
                    break;
                }
                for(int i=0; i<10; i++)
                {
                    if(queue[i]==0)
                    {
                        break;
                    }
                    printf("%d ",queue[i]);
                }
                printf("\n");
                break;
            case 4: //quit
                return 0;
        }
    }
}