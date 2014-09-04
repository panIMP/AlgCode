#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <iostream>

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
    };

    std::string findMaxSharedStr(const std::string& compare, SHARE_STR_TYPE type) const;
    std::string findMaxSharedStr(const MyString& compare, SHARE_STR_TYPE type) const;
    void buildPalindromeStr();

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    void setStr(const std::string& str) {mStr = str;}
    const std::string& getStr() const {return mStr;}

private:
    void grabShareSequence(int& i, int& j, std::string& shareSeq, int **table, int **array);
    std::string mStr;
};


std::ostream& operator<<(std::ostream& os, const MyString& str);
std::istream& operator>>(std::istream& is, MyString& str);



#endif // MYSTRING_H
