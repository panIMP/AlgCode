#ifndef MYRCSTRING_H
#define MYRCSTRING_H

#include "myClass/MyRCObject.h"
#include "myClass/MyRCPtr.h"
#include <string.h>

class MyRCString
{
public:
    MyRCString(const char* initValue = "") : mValue(new StringValue(initValue))
    {
        cout << "Done" << endl;
    }

    const char& operator [] (int index) const
    {
        return mValue->mData[index];
    }

    char& operator [] (int index)
    {
        if (mValue->isShared())
        {
            mValue = new StringValue(mValue->mData);
        }

        mValue->markUnshareable();

        return mValue->mData[index];
    }

private:
    class StringValue : public MyRCObject
    {
    public:
        StringValue(const char* initData)
        {
            init(initData);
        }

        StringValue(const StringValue& rhs)
        {
            init(rhs.mData);
        }

        ~StringValue()
        {
            delete[] mData;
            mData = nullptr;
        }

        void init(const char* initData)
        {
            mData = new char[strlen(initData) + 1];
            strcpy(mData, initData);
        }

    public:
        char* mData;
    };

    MyRCPtr<StringValue> mValue;
};


#endif // MYRCSTRING_H
