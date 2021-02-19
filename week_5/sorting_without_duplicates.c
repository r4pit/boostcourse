#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int num[N];
    for (int i=0; i<N; i++)
        scanf("%d", &num[i]);
    qsort(num, N, sizeof(int), compare);
    int tmp = 0;
    for (int i=0; i<N; i++)
    {
        if (tmp != num[i])
        {
            printf("%d ", num[i]);
            tmp = num[i];
        }
    }
}