#include <stdio.h>
#include <string.h>

int main(void)
{
    int loca_int;
    printf("location: ");
    scanf("%d", &loca_int);
    
    int n = 0;
    int tmp = loca_int;
    while (tmp != 0)
    {
        tmp = tmp/10;
        n++;
    }
    // int to string
    char loca_str[100];
    sprintf(loca_str,"%d", loca_int);

    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + loca_str[i] - 48;
    }
    printf("optimal location: %d\n", sum/n);
}