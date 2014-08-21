#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int verifyMsisdn(char* inMsisdn)
{
    int len = strlen(inMsisdn);

    if (len != 13)
        return 1;

    long long int phoneNum = 0;
    if (sscanf(inMsisdn, "%lld", &phoneNum) < 1)
        return 2;

    if (phoneNum < 10e11)
        return 2;

    if (phoneNum < 86e11 || phoneNum >= 87e11)
        return 3;

    else
        return 0;
}



int phoneNum()
{
    char str[1024] = {'\0'};
    fgets(str, 1024, stdin);

    int retVal = verifyMsisdn(str);

    return retVal;
}
