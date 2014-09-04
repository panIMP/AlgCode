#include <iostream>

using namespace std;

class InsertPalindrome
{
public:
    InsertPalindrome(string& str) : palindromeString_(str)
    {
    }

    int countMinimumInsert()
    {
        int dpNum[100][100];

        int sizeStr = palindromeString_.size();
        // init
        for (int i = 0; i < sizeStr; ++i)
        {
            dpNum[i][i] = 0;
        }
        for (int i = 0; i < sizeStr - 1; ++i)
        {
            if (palindromeString_[i] == palindromeString_[i+1])
                dpNum[i][i+1] = 0;
            else
                dpNum[i][i+1] = 1;
        }

        for (int j = 2; j < sizeStr; ++j)
        {
            for (int i = 0; i < sizeStr - j; ++i)
            {
                if (palindromeString_[i] == palindromeString_[i+j])
                {
                    dpNum[i][i+j] = dpNum[i+1][i+j-1];
                }
                else
                {
                    dpNum[i][i+j] = min(dpNum[i][i+j-1], dpNum[i+1][i+j]) + 1;
                }
            }
        }

        insertCharacter(dpNum);

        return dpNum[0][sizeStr - 1];
    }

    void insertCharacter(int dpNum[][100])
    {
        // int** dpNum = reinterpret_cast<int **>(dp);
        int sizeStr = palindromeString_.size();
        int x = 0, y = sizeStr - 1;
        int startPos = 0;
        string temp(palindromeString_);

        while (y > x)
        {
            if (palindromeString_[y] == palindromeString_[x])
            {
                ++ x;
                -- y;
            }
            else if (dpNum[x + 1][y] < dpNum[x][y - 1])
            {
                //temp = temp.insert(y + startPos + 1, 1, palindromeString_[x]);
                temp.insert(y + startPos + 1, 1, palindromeString_[x]);
                ++ x;
            }
            else
            {
                //temp = temp.insert(x + startPos, 1, palindromeString_[y]);
                temp.insert(x + startPos, 1, palindromeString_[y]);
                ++ startPos;
                -- y;
            }
        }

        palindromeString_ = temp;
    }


    void insertCharacter2(int dpNum[][100])
    {
        // int** dpNum = reinterpret_cast<int **>(dp);
        int sizeStr = palindromeString_.size();
        int x = 0, y = sizeStr - 1;
        int startPos = 0;
        string temp;
        temp.resize(sizeStr + dpNum[0][sizeStr - 1]);
        temp = palindromeString_;
        while (y > x)
        {
            if (palindromeString_[y] == palindromeString_[x])
            {
                ++ x;
                -- y;
            }
            else if (dpNum[x + 1][y] < dpNum[x][y - 1])
            {
                temp.insert(y + startPos + 1, 1, palindromeString_[x]);
                ++ x;
            }
            else
            {
                temp.insert(x + startPos, 1, palindromeString_[y]);
                ++ startPos;
                -- y;
            }
        }

        palindromeString_ = std::move(temp);
    }

    void printString()
    {
        cout << palindromeString_ << endl;
    }
private:
    string palindromeString_;
};


//int main()
//{
//    string str;

//    while (cin >> str)
//    {
//        InsertPalindrome ip(str);

//        cout << ip.countMinimumInsert() << endl;
//        ip.printString();
//    }

//    return 0;
//}
