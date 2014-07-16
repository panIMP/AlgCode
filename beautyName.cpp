#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void bubbleSort(int a[], int len) {
    int tmp, i, j;

    for (i = 0; i < len-1; ++i) {
        for (j = 0; j < len-1-i; ++j) {
            if (a[j] < a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}


int beautyName()
{
    int hist[26] = {0};
    char str[1024] = {'\0'};
    int nameNum = 0;
    int i = 0;
    unsigned int j = 0;
    int* value = NULL;

    if (scanf_s("%d", &nameNum) < 1)
        return -1;

    getchar();
    value = (int*)calloc(nameNum, sizeof(int));

    for (i = 0; i < nameNum; ++i)
    {
        memset(str, 0, strlen(str));
        memset(hist, 0, 26);

        if(gets_s(str, 1024) == NULL)
            return -1;

        for (j = 0; j < strlen(str); ++j)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                hist[str[j] - 'a']++;
            else if(str[j] >= 'A' && str[j] <= 'Z')
                hist[str[j] - 'A']++;
        }

        bubbleSort(hist, 26);

        for (j = 0; j < 26; ++j)
        {
            value[i] += (26-j)*hist[j];
        }
    }

    for (i = 0; i < nameNum; ++i)
    {
        printf("%d\n", value[i]);
    }


    return 0;
}








