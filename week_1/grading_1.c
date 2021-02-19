#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int score;
    char *grade_char[9] = {"A+","A","B+","B","C+","C","D+","D","F"};
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
        int grade_number = -1;
        for(int tmp_score = (100 - score); tmp_score > 0; tmp_score = (tmp_score - 5))
        {
            grade_number++;
        }
        if(grade_number == -1)
        {
            grade_number++;
        }
        if(grade_number > 8)
        {
            grade_number = 8;
        }
        printf("학점은 %s 입니다.\n", grade_char[grade_number]);
    }
    
}
