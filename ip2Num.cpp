#include <stdio.h>

int ip2Num()
{
    char strIP[1024] = {'\0'};
    long numIP = 0;
    long a[4] = {0};
    long pow166 = 16 * 16 * 16 * 16 * 16 * 16;
    long pow164 = 16 * 16 * 16 * 16;
    long pow162 = 16 * 16;

    if (gets_s(strIP, 1024) == NULL)
        return -1;

    if (scanf_s("%ld", &numIP) != 1)
        return -1;

    if (sscanf_s(strIP, "%ld.%ld.%ld.%ld", &a[0], &a[1], &a[2], &a[3]) < 4)
        return -1;

    if (a[0] > 255 || a[0] < 0 || a[1] > 255 || a[1] < 0 || a[2] > 255 || a[2] < 0 || a[3] > 255 || a[3] < 0)
        return -1;


    a[0] = a[0] * pow166 + a[1] * pow164 + a[2] * pow162 + a[3];
    printf("%ld\n", a[0]);

    a[0] = numIP / pow166;
    a[1] = (numIP  - a[0] * pow166) / pow164;
    a[2] =  (numIP  - a[0] * pow166 - a[1] * pow164) / pow162;
    a[3] = numIP % pow162;

    printf("%ld.%ld.%ld.%ld", a[0], a[1], a[2], a[3]);

    return 0;
}
