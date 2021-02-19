#include <stdio.h>

int main(void)
{
    int arr[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
}