#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <set>
#include <functional>


using namespace std;


class packString
{
public:
    string s;
    int i;

    packString(const string& str, const int& iVal) :s(str), i(iVal) {}
};


class comp
{
public:
    bool operator() (const packString& a, const packString& b)
    {
        if (a.s == b.s)
            return false;

        if (a.s.length() > b.s.length())
            return true;
        if (a.s.length() < b.s.length())
            return false;
        if (a.s.length() == b.s.length())
        {
            return a.i < b.i;
        }
    }
};



void my_word(char input[], char output[])
{
    char subStr[100] = { '\0' };
    int len = strlen(input);
    set<packString, comp> subStrArr;

    int i = 0;
    while (i < len)
    {
        if (!isalpha(input[i]))
        {
            i++;
            continue;
        }

        sscanf(input + i, "%[a-zA-Z]", subStr);

        if (strlen(subStr) > 1)
        {
            subStrArr.insert(packString(string(subStr), i));
            i += strlen(subStr);
        }
        else
        {
            i++;
        }
    }

    if (subStrArr.size() == 0)
    {
        output[0] = ' ';
        return;
    }


    //set<packString, comp>::iterator pos;
    for (auto pos = subStrArr.begin(); pos != subStrArr.end(); ++pos)
    {
        strcat(output, pos->s.c_str());
        strcat(output, " ");
    }

    output[strlen(output) - 1] = '\0';
}



int wordExtract()
{
    char str[1024] = { '\0' };
    char outStr[1024] = { '\0' };

    fgets(str, 1024, stdin);

    my_word(str, outStr);

    puts(outStr);

    system("pause");

    return 0;
}
