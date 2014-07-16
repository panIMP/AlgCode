#include <stdio.h>
#include <string.h>

int lastWord()
{
    char str[2048] = {'\0'};
    char* tmpStr = NULL;
    int len = 0;
	char* p;

    if (gets_s(str, 1024) == NULL)
        return -1;

    tmpStr = strtok_s(str, " ", &p);
    while (tmpStr != NULL) {
        len = strlen(tmpStr);
		tmpStr = strtok_s(NULL, " ", &p);
    }

    printf("%d", len);

	return 0;
}
