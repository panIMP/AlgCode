#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int
cal_score(int score[], int judge_type[], int n)
{
    long long zhuanAvr = 0;
    long long dazhAvr = 0;
    int zhuanNum = 0;
    int dazhNum = 0;

    for (int i = 0; i < n; ++i)
    {
        if (judge_type[i] == 1)
        {
            zhuanAvr += score[i];
            zhuanNum ++;
        }
        else
        {
            dazhAvr += score[i];
            dazhNum ++;
        }
    }

    if (dazhNum == 0)
        return (int)(zhuanAvr / zhuanNum);

    else
        return (int)(0.6 * (double)(zhuanAvr / zhuanNum) + 0.4 * (double)(dazhAvr / dazhNum));
}


int score(int argc, char* argv[])
{
    int score[1024] = {0};
    int judge_type[1024] = {0};
    char str[1024] = {'\0'};
    char* tmpStr;
    int i = 0;
    int j = 0;
    int len = 0;

    printf("input the scores:\n");
    gets(str);
    len = strlen(str);
    tmpStr = strtok(str, " ");
    while (tmpStr != NULL) {
        score[i] = atoi(tmpStr);
        tmpStr = strtok(NULL, " ");
        i++;
    }

    printf("input the judge type:\n");
    memset(str, 0, len);
    gets(str);
    tmpStr = strtok(str, " ");
    while (tmpStr != NULL) {
        judge_type[j] = atoi(tmpStr);
        tmpStr = strtok(NULL, " ");
        j++;
    }

    if (j != i)
        return -1;

    int finalScore = cal_score(score, judge_type, i);

    printf("%d", finalScore);

    return 0;
}





















