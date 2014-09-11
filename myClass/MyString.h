#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <iostream>
#include "hpFun.h"

class MyString
{
public:
    MyString() = default;
    MyString(const char* str) : mStr(str) {}
    MyString(const std::string& str) : mStr(str) {}
    MyString(MyString& rhs) : mStr(rhs.mStr) {}

    enum SHARE_STR_TYPE
    {
        CONTINUED_STR = 0,
        NON_CONTINUED_OK_STR,
    };

    enum ARROW_FLAG
    {
        LEFT = 0,
        UP,
        LEFT_UP,

        DOWN,
        LEFT_DOWN,
    };

    int toInt();

    long long toLonglong();

    // returns the max-lenght shared sequence between two string
    std::string findMaxSharedSeq(const MyString& compare, SHARE_STR_TYPE type) const;
    std::string findMaxSharedSeq(const std::string& compare, SHARE_STR_TYPE type) const;

    // returns the palindrome string of mStr by the minimum insertion of characters
    std::string buildPalindromeStr();

    friend std::ostream& operator << (std::ostream& os, const MyString& str);
    friend std::istream& operator >> (std::istream& is, MyString& str);

    void setStr(const std::string& str) {mStr = str;}
    const std::string& getStr() const {return mStr;}

private:
    // a reptile to trace back the formulation routine from the maximum-len position
    void grabShareSequence(int i, int j, const int& n, std::string& shareSeq, const int* const array) const;
    // a reptile to trace back the formulation routine from the minimum-insert num position
    // leftPos and rightPos are the insert index for insert from begin and back from end respectively
    void insertForPalindromeStr(int i, int j, int leftPos, int rightPos, std::string& palinStr, const int* const array) const;
    std::string mStr;
};


std::ostream& operator << (std::ostream& os, const MyString& str);
std::istream& operator >> (std::istream& is, MyString& str);



#endif // MYSTRING_H
