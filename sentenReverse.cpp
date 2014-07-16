#include <stack>
#include <string>
#include <string.h>

using namespace std;


int sentenReverse(int argc, char* argv[])
{
    char str[1024] = {'\0'};
    stack<string> strStack;
    string subStr;
    char* tmpStr;

    if (gets(str) == NULL)
        return -1;

    tmpStr = strtok(str, " ");
    while (tmpStr != NULL)
    {
        subStr = string(tmpStr);
        strStack.push(subStr);
        tmpStr = strtok(NULL, " ");
    }

    while (! strStack.empty())
    {
        subStr = strStack.top();
        strStack.pop();
        printf("%s", subStr.c_str());
        if (strStack.empty())
            continue;
        else
            printf(" ");
    }

    return 0;
}
