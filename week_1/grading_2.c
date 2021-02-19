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
        if(score >= 95) printf("학점은 A+ 입니다.");
        else if(score >= 90) printf("학점은 A 입니다.");
        else if(score >= 85) printf("학점은 B+ 입니다.");
        else if(score >= 80) printf("학점은 B 입니다.");
        else if(score >= 75) printf("학점은 C+ 입니다.");
        else if(score >= 70) printf("학점은 C 입니다.");
        else if(score >= 65) printf("학점은 D+ 입니다.");
        else if(score >= 60) printf("학점은 D 입니다.");
        else printf("학점은 F 입니다.");
    }

}