#include <stdio.h>
#include <string.h>

int lastWord()
{
    char str[2048] = {'\0'};
    char* tmpStr = NULL;
    int len = 0;

    if (fgets(str, 1024, stdin) == NULL)
        return -1;

    tmpStr = strtok(str, " ");
    while (tmpStr != NULL) {
        len = strlen(tmpStr);
        tmpStr = strtok(NULL, " ");
    }

    printf("%d", len);

	return 0;
}
