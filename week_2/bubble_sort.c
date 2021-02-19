#include <stdio.h>

int main(void)
{
    int number[5] = {4,5,3,2,4};

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(number[j] > number[j+1])
            {
                int tmp = number[j];
                number[j] = number[j+1];
                number[j+1] = tmp;
            }
        }
    }

    for (int i=0; i<5; i++)
    {
        printf("%d ",number[i]);
    }
    printf("\n");
}