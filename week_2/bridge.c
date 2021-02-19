#include<stdio.h>

void move(int *here);
int time = 0;

int main()
{
    printf("how many people?: ");
    int people;
    scanf("%d", &people);
    if (people > 100)
    {
        printf("please enter a number less then 100\n");
        return 1;
    }
    int moving_time[100] = {0, };
    for (int i=0; i<people; i++)
    {
        printf("person %d: ", i+1);
        scanf("%d", &moving_time[i]);
        if (moving_time[i] == 0)
        {
            printf("zero cannot be entered\n");
            return 1;
        }
    }

    // sort
    for (int i=0; i<people-1; i++)
    {
        for (int j=0; j<people-1; j++)
        {
            if (moving_time[j]>moving_time[j+1])
            {
                int tmp = moving_time[j];
                moving_time[j] = moving_time[j+1];
                moving_time[j+1] = tmp;
            }
        }
    }
    move(moving_time);
    return 0;
}

void move(int *here)
{
    // count people remaining
    int count = 0;
    while(here[count] != 0)
    {
        count++;
    }
    if (count == 2)
    {
        time = time + here[1];
        printf("move %d %d, total %d elapsed\n", here[0], here[1], time);
        printf("total time %i elapsed\n", time);
    }
    else if (count == 3)
    {
        time = time + here[1];
        printf("move %d %d, total %d elapsed\n", here[0], here[1], time);
        time = time + here[0];
        printf("move %d, total %d elapsed\n", here[0], time);
        time = time + here[2];
        printf("move %d %d, total %d elapsed\n", here[0], here[2], time);
        printf("total time %i elapsed\n", time);
    }
    else
    {
        time = time + here[1];
        printf("move %d %d, total %d elapsed\n", here[0], here[1], time);
        time = time + here[0];
        printf("move %d, total %d elapsed\n", here[0], time);
        time = time + here[count-1];
        printf("move %d %d, total %d elapsed\n", here[count-2], here[count-1], time);
        time = time + here[1];
        printf("move %d, total %d elapsed\n", here[1], time);
        here[count-1] = 0;
        here[count-2] = 0;
        move(here);
    }
}