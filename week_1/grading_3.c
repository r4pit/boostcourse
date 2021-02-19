#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int score;
    while(1)
    {
        printf("점수:");
        scanf("%i",&score);
        if(score == -1)
        {
            return 0;
        }
        if(score < 0 || score > 100)
        {
            printf("성적을 올바르게 입력하세요!");
            continue;
        }
        switch(score/5)
        {
            case 20:
                printf("학점은 A+ 입니다.");
                break;
            case 19:
                printf("학점은 A+ 입니다.");
                break;
            case 18:
                printf("학점은 A 입니다.");
                break;
            case 17:
                printf("학점은 B+ 입니다.");
                break;
            case 16:
                printf("학점은 B 입니다.");
                break;
            case 15:
                printf("학점은 C+ 입니다.");
                break;
            case 14:
                printf("학점은 C 입니다.");
                break;
            case 13:
                printf("학점은 D+ 입니다.");
                break;
            case 12:
                printf("학점은 D 입니다.");
                break;
            default:
                printf("학점은 F 입니다.");
                break;
        }
    }

}