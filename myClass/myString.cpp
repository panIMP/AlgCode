#include "myString.h"
#include <string.h>

using namespace std;


std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    return os << str.mStr << std::endl;
}


std::istream& operator>>(std::istream& is, MyString& str)
{
    is >> str.mStr;
    if (!is)
        str = MyString();

    return is;
}


std::string MyString::findMaxSharedStr(const std::string& compare, MyString::SHARE_STR_TYPE type) const
{
    if (&compare == &(this->mStr))
        return this->mStr;

    string sharedStr;
    int m = this->mStr.size();
    int n = compare.size();
    int** table = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        table[i] = new int[n + 1];
        memset(table[i], 0, sizeof(int) * (n + 1));
    }

    switch (type)
    {
    case NON_CONTINUED_OK_STR:
    {
        int** arrowFlag = new int*[m + 1];
        for (int i = 0; i < m + 1; ++i)
        {
            arrowFlag[i] = new int[n + 1];
            memset(arrowFlag[i], 0, sizeof(int) * (n + 1));
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    arrowFlag[i+1][j+1] = LEFT_UP;
                }
                else if (table[i][j+1] > table[i+1][j])
                {
                    table[i+1][j+1] = table[i][j+1];
                    arrowFlag[i+1][j+1] = UP;
                }
                else
                {
                    table[i+1][j+1] = table[i+1][j];
                    arrowFlag[i+1][j+1] = LEFT;
                }
            }
        }
    }
        break;

    case CONTINUED_STR:
    {
        int iEndPos = 0;
        int maxShareLen = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    if (maxShareLen < table[i+1][j+1])
                    {
                        maxShareLen = table[i+1][j+1];
                        iEndPos = i;
                    }
                }
                else
                    table[i+1][j+1] = 0;
            }
        }

        sharedStr.insert(0, mStr, iEndPos-maxShareLen + 1,  maxShareLen);
    }
        break;

    default:
        break;
    }


    return sharedStr;
}


std::string MyString::findMaxSharedStr(const MyString& myCompare, MyString::SHARE_STR_TYPE type) const
{
    if (&myCompare == this)
        return this->mStr;

    string sharedStr;
    string compare = myCompare.getStr();
    int m = this->mStr.size();
    int n = compare.size();
    int** table = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        table[i] = new int[n + 1];
        memset(table[i], 0, sizeof(int) * (n + 1));
    }

    switch (type)
    {
    case NON_CONTINUED_OK_STR:
    {
        int** arrowFlag = new int*[m + 1];
        for (int i = 0; i < m + 1; ++i)
        {
            arrowFlag[i] = new int[n + 1];
            memset(arrowFlag[i], 0, sizeof(int) * (n + 1));
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    arrowFlag[i+1][j+1] = LEFT_UP;
                }
                else if (table[i][j+1] > table[i+1][j])
                {
                    table[i+1][j+1] = table[i][j+1];
                    arrowFlag[i+1][j+1] = UP;
                }
                else
                {
                    table[i+1][j+1] = table[i+1][j];
                    arrowFlag[i+1][j+1] = LEFT;
                }
            }
        }
    }
        break;

    case CONTINUED_STR:
    {
        int iEndPos = 0;
        int maxShareLen = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    if (maxShareLen < table[i+1][j+1])
                    {
                        maxShareLen = table[i+1][j+1];
                        iEndPos = i;
                    }
                }
                else
                    table[i+1][j+1] = 0;
            }
        }

        sharedStr.insert(0, mStr, iEndPos-maxShareLen + 1,  maxShareLen);
    }
        break;

    default:
        break;
    }


    return sharedStr;
}



void MyString::buildPalindromeStr()
{

}



int main()
{
    MyString strA, strB;
    cin >> strA >> strB;

    cout << strA.findMaxSharedStr(strB, MyString::CONTINUED_STR) << endl;

    return 0;
}
