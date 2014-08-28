#include <string.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


int isJoker(const vector<string>& str)
{
    if (str.size() == 1)
    {
        if (str[0] == "joker" || str[0] == "JOKER")
            return 1;
    }

    return 0;
}


int isBoom(const vector<string>& str)
{
    if (str.size() == 4)
    {
        string value = str[0];
        if ((str[0] == value) && (str[1] == value) && (str[2] == value) && (str[3] == value))
        {
            return 1;
        }
    }
    return 0;
}


int isjokerJoker(const vector<string>& str)
{
    if (str.size() == 2)
    {
        if (str[0] == "joker" && str[1] == "JOKER")
        {
            return 1;
        }
    }
    return 0;
}


int poker(int argc, char* argv[])
{
    // input and parse string
    char str[200] = {'\0'};
    char* tmpPreStr;
    char* tmpPostStr;
    char preStr[100] = {'\0'};
    char postStr[100] = {'\0'};

    vector<string> preStrArray;
    vector<string> postStrArray;

    preStrArray.clear();
    postStrArray.clear();
    memset(str,0,200);
    memset(preStr,0,100);
    memset(postStr,0,100);

    if (fgets(str, 1024, stdin) == NULL)
        return -1;

    char* tmpStr = NULL;
    tmpPreStr = strtok(str, "-");
    memcpy(preStr, tmpPreStr, strlen(tmpPreStr));
    tmpPostStr = strtok(NULL, "-");
    memcpy(postStr, tmpPostStr, strlen(tmpPostStr));

    tmpStr = strtok(tmpPreStr, " ");
    while (tmpStr != NULL) {
        string tmpStr2 = string(tmpStr);
        if (tmpStr2 == "10")
            tmpStr2 = "A";
        else if (tmpStr2 == "J")
            tmpStr2 = "B";
        else if (tmpStr2 == "Q")
            tmpStr2 = "C";
        else if (tmpStr2 == "K")
            tmpStr2 = "D";
        else if (tmpStr2 == "A")
            tmpStr2 = "E";
        else if (tmpStr2 == "2")
            tmpStr2 = "F";

        preStrArray.push_back(tmpStr2);
        tmpStr = strtok(NULL, " ");
    }
    tmpStr = strtok(tmpPostStr, " ");
    while (tmpStr != NULL) {
        string tmpStr2 = string(tmpStr);
        if (tmpStr2 == "10")
            tmpStr2 = "A";
        else if (tmpStr2 == "J")
            tmpStr2 = "B";
        else if (tmpStr2 == "Q")
            tmpStr2 = "C";
        else if (tmpStr2 == "K")
            tmpStr2 = "D";
        else if (tmpStr2 == "A")
            tmpStr2 = "E";
        else if (tmpStr2 == "2")
            tmpStr2 = "F";

        postStrArray.push_back(tmpStr2);
        tmpStr = strtok(NULL, " ");
    }

    int preLen = preStrArray.size();
    int postLen = postStrArray.size();

    // compare
    if (isJoker(preStrArray))
    {
        if (isJoker(postStrArray))
        {
            if (preStrArray[0] > postStrArray[0])
                puts(preStr);
            else
                puts(postStr);
        }

        else if (isBoom(postStrArray))
            puts(postStr);

        else if (isjokerJoker(postStrArray))
            puts(postStr);

        else if (postLen == 1)
            puts(preStr);

        else
            printf("ERROR\n");
    }

    else if (isBoom(preStrArray))
    {
        if (isBoom(postStrArray))
        {
            if (preStrArray[0] > postStrArray[0])
                puts(preStr);
            else
                puts(postStr);
        }

        else if (isjokerJoker(postStrArray))
            puts(postStr);

        else
            puts(preStr);
    }

    else if (isjokerJoker(preStrArray))
    {
        puts(preStr);
    }

    else
    {
        if (isJoker(postStrArray))
        {
            if (preLen == 1)
                puts(postStr);
            else
                printf("ERROR\n");
        }

        else if (isBoom(postStrArray))
            puts(postStr);

        else if (isjokerJoker(postStrArray))
            puts(postStr);

        else
        {
            if (preLen == postLen)
            {
                if (preStrArray[0] > postStrArray[0])
                    puts(preStr);
                else
                    puts(postStr);
            }
            else
            {
                printf("ERROR\n");
            }
        }
    }

    return 0;
}


















