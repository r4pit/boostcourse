#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    // 정답
    int answer[10] = {1,2,3,4,5,1,2,3,4,5};
    int omr[10];
    char *grade_alphabet[9] = {"A+","A","B+","B","C+","C","D+","D","F"};
    int correct_answer = 0;
    int score;
    int grade_number = -1;
    if(argc != 11)
    {
        printf("문제는 10문제입니다. 현재 %d개의 답안을 제출했습니다.\n", argc - 1);
        return 1;
    }
    // string to int
    for(int i=1; i<argc; i++)
    {
        // 답 범위 확인
        omr[(i-1)] = atoi(argv[i]);
        if(omr[i-1] > 5 || omr[i-1] < 1)
        {
            printf("답의 범위는 1 ~ 5 입니다.\n");
            return 1;
        }
    }
    // 답 확인
    for(int i=0; i<10; i++)
    {
        if(answer[i] == omr[i])
        {
            correct_answer++;
        }
    }
    // 점수 계산
    score = correct_answer * 10;
    // 등급 계산
    for(int tmp_score = (100 - score); tmp_score>0; tmp_score = (tmp_score - 5))
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
    // 출력
    printf("점수: %i 등급: %s\n", score, grade_alphabet[grade_number]);
    return 0;
}