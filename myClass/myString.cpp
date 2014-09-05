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


// returns the max-lenght shared sequence between two string
std::string MyString::findMaxSharedSeq(const MyString& myCompare, MyString::SHARE_STR_TYPE type) const
{
    if (&myCompare == this)
        return this->mStr;

    if (myCompare.getStr().c_str() == nullptr)
        return nullptr;

    // the shared character sequence in the two comparing string
    string sharedSeq;

    // compare string
    string compare = myCompare.getStr();

    // init 2-dimentional mark table for dp
    int m = this->mStr.size();
    int n = compare.size();
    int** table = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        table[i] = new int[n + 1];
        memset(table[i], 0, sizeof(int) * (n + 1));
    }

    // start dp
    switch (type)
    {
    // if the shared sequence can be non continued that is scattered in the two comparing string
    // the recursive formula will be
    // f(i, j)    = f(i -1, j-1) + 1;           ==> strA[i] = strB[j]
    //         or = min[f(i,j-1), f(i+1,j)];    ==> strA[i] != strB[j]
    // Here: i,j are the tail index in the two comparing string
    case NON_CONTINUED_OK_STR:
    {
        int* arrowFlag = new int[(m+1) * (n+1)];

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curPos = (i+1)*n + j+1;
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    arrowFlag[curPos] = LEFT_UP;
                }
                else if (table[i][j+1] > table[i+1][j])
                {
                    table[i+1][j+1] = table[i][j+1];
                    arrowFlag[curPos] = UP;
                }
                else
                {
                    table[i+1][j+1] = table[i+1][j];
                    arrowFlag[curPos] = LEFT;
                }
            }
        }

        // reconstruct the shared string liking using a reptile
        grabShareSequence(m, n, n, sharedSeq, arrowFlag);

        // free arrow flag array
        delete arrowFlag;
        arrowFlag = nullptr;
    }
        break;

    // if the shared sequence must be continued that is a substr in the two comparing string
    // the recursive formula will be
    // f(i, j)    = f(i -1, j-1) + 1;    ==> strA[i] = strB[j]
    //         or = 0                    ==> strA[i] != strB[j]
    // Here: i,j are the tail index in the two comparing string
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

        // find the start and end position in the source string to extract the shared string
        sharedSeq.insert(0, mStr, iEndPos-maxShareLen + 1,  maxShareLen);
    }
        break;

    default:
        break;
    }

    // free table
    for (int i = 0; i < m; ++i)
    {
        delete table[i];
        table[i] = nullptr;
    }
    delete table;
    table = nullptr;

    return sharedSeq;
}


// same function and details as above
std::string MyString::findMaxSharedSeq(const std::string& compare, MyString::SHARE_STR_TYPE type) const
{
    if (&compare == &(this->mStr))
        return this->mStr;

    if (compare.c_str() == nullptr)
        return nullptr;

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
        int* arrowFlag = new int[(m+1) * (n+1)];

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curPos = (i+1)*n + j+1;
                if (mStr[i] == compare[j])
                {
                    table[i+1][j+1] = table[i][j] + 1;
                    arrowFlag[curPos] = LEFT_UP;
                }
                else if (table[i][j+1] > table[i+1][j])
                {
                    table[i+1][j+1] = table[i][j+1];
                    arrowFlag[curPos] = UP;
                }
                else
                {
                    table[i+1][j+1] = table[i+1][j];
                    arrowFlag[curPos] = LEFT;
                }
            }
        }

        grabShareSequence(m, n, n, sharedStr, arrowFlag);

        delete arrowFlag;
        arrowFlag = nullptr;
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

    for (int i = 0; i < m; ++i)
    {
        delete table[i];
        table[i] = nullptr;
    }
    delete table;
    table = nullptr;

    return sharedStr;
}


// a reptile to trace back the formulation routine from the maximum-len position
void MyString::grabShareSequence(int i, int j, const int& n, std::string& shareSeq, const int* const array) const
{
    if (i == 0 || j == 0)
        return;

    int curPos = i * n + j;

    // if at (i,j) strA[i] == strB[j], then insert current character into shared string
    if (array[curPos] == LEFT_UP)
    {
        shareSeq.insert(shareSeq.begin(), mStr[i-1]);
        grabShareSequence(i-1, j-1, n, shareSeq, array);
    }
    // search left to find another equ position
    else if (array[curPos] == LEFT)
    {
        grabShareSequence(i, j-1, n, shareSeq, array);
    }
    // search up to find another equ position
    else if (array[curPos] == UP)
    {
        grabShareSequence(i-1, j, n, shareSeq, array);
    }
}


// returns the palindrome string of mStr by the minimum insertion of characters
string MyString::buildPalindromeStr()
{
    string palinStr = mStr;

    // init table
    int m = this->mStr.size();
    int** table = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        table[i] = new int[m];
        memset(table[i], 0, sizeof(int) * m);
    }

    // init arrow mark
    int* arrowFlag = new int[m*m];
    memset(arrowFlag, 0, sizeof(int)*m*m);

    // the recursive formula will be
    // f(i, j)    = f(i+1, j-1) ;                   ==> strA[i] = strB[j]
    //         or = 1 + min[f(i+1,j), f(i,j-1)];    ==> strA[i] != strB[j]
    // Here: i,j are the head and tail index of the string respectively

    // init f(0,0),f(1,1)....
    for (int i = 0; i < m; ++i)
        table[i][i] = 0;

    // init f(0,1),f(1,2),f(2,3)...
    for (int i = 0; i < m-1; ++i)
    {
        table[i][i+1] = (mStr[i] == mStr[i+1] ? 0 : 1);
    }

    // do the formula sequently
    for (int step = 2; step < m; ++step)
    {
        for (int i = 0; i < m - step; ++i)
        {
            int curPos = i * m + i + step;
            if (mStr[i] == mStr[i+step])
            {
                table[i][i+step] = table[i+1][i+step-1];
                arrowFlag[curPos] = LEFT_DOWN;
            }
            else if (table[i+1][i+step] < table[i][i+step-1])
            {
                table[i][i+step] = 1 + table[i+1][i+step];
                arrowFlag[curPos] = DOWN;
            }
            else
            {
                table[i][i+step] = 1 + table[i][i+step-1];
                arrowFlag[curPos] = LEFT;
            }
        }
    }

    // insert the necessary character in the right position to form a palindrome string
    insertForPalindromeStr(0, m-1, 0, 0, palinStr, arrowFlag);

    // free memory
    for (int i = 0; i < m; ++i)
    {
        delete table[i];
        table[i] = nullptr;
    }
    delete table;
    table = nullptr;

    delete arrowFlag;
    arrowFlag = nullptr;

    return palinStr;
}


// a reptile to trace back the formulation routine from the minimum-insert num position
// leftPos and rightPos are the insert index for insert from begin and back from end respectively
void MyString::insertForPalindromeStr(int i, int j, int leftPos, int rightPos, std::string& palinStr, const int* const array) const
{
    if (i >= j)
        return;

    int curPos = i * mStr.size() + j;

    if (array[curPos] == LEFT_DOWN)
    {
        insertForPalindromeStr(i+1, j-1, ++leftPos, ++rightPos, palinStr, array);
    }
    else if (array[curPos] == LEFT)
    {
        palinStr.insert(palinStr.begin() + leftPos, mStr[j]);
        insertForPalindromeStr(i, j-1, ++leftPos, ++rightPos, palinStr, array);
    }
    else if (array[curPos] == DOWN)
    {
        palinStr.insert(palinStr.end() - rightPos, mStr[i]);
        insertForPalindromeStr(i+1, j, ++leftPos, ++rightPos, palinStr, array);
    }
}


int main()
{
    MyString strA;
    cin >> strA;

    cout << strA.buildPalindromeStr() << endl;

    return 0;
}
