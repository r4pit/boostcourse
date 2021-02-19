#include <stdio.h>

int check(int test)
{
    return !test;
}

int main(void)
{
    int test[5] = {1,2,3,4,5};
    int test2 = 2;
    int test3 = 0;
    char *test4 = NULL;
    printf("test2 is %d\n", test2);
    printf("%d\n", test[++test2]);
    printf("test2 is %d\n", test2);
    printf("%d\n", test[test2 +1]);
    printf("test2 is %d\n", test2);
    printf("!test2 is %d\n", !test2);
    printf("test2 is !%d\n", check(test2));
    printf("test3 is !%d\n", check(test3));
    return 0;
}