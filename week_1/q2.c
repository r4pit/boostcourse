#include <stdio.h>
#define SIZE 500000

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    int sum_txt = 0;
    int sum_n = 0;
    int result = 0;
    for (int i=1; i <= n; i++)
    {
        sum_n = sum_n + i;
    } 
    printf("sum: %d\n", sum_n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int part_arr[SIZE];
    int length_of_part_arr = n-1;
    for(int i=0; i < length_of_part_arr; i++)
    {
        scanf("%d", &part_arr[i]);
        sum_txt = sum_txt + part_arr[i];
    }
    // n과 part_arr를 이용해 k 구하기
    printf("now: %d\n", sum_txt);
    result = (sum_n - sum_txt);
    printf("result: %d\n", result);
    return 0;
}