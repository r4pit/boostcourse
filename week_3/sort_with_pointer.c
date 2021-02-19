#include <stdio.h>

void sort(int n, int *arr);

int main(void)
{
    int n = 7;
    int arr[7] = {0,25,10,17,6,12,9};
    sort(n,arr);
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int n, int *arr)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1; j++)
        {
            if (*(arr+j) > *(arr+j+1))
            {
                int tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = tmp;
            }
        }
    }
}