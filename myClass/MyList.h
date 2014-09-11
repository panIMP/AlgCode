#ifndef MYLIST_H
#define MYLIST_H

#include <memory>
#include "hpFun.h"


template<typename T>
class MySigList
{
    class MySigListNode;
    typedef std::shared_ptr<MySigListNode> ShareNodePtr;

public:
    ShareNodePtr findKthToTail(int k)
    {
        if (k < 1 || k > mSize)
        {
            DEBUG_PRINT("invalid input position of k!");
            return nullptr;
        }
        if (mHead == nullptr)
        {
            DEBUG_PRINT("list is null!");
            return nullptr;
        }

        ShareNodePtr ptrAhead = mHead;
        ShareNodePtr ptrBehind = mHead;

        for (int i = 0; i < k-1; ++i)
            ptrBehind = ptrBehind->mNext;

        while (ptrBehind->mNext != nullptr)
        {
            ptrAhead = ptrAhead->mNext;
            ptrBehind = ptrBehind->mNext;
        }

        return ptrAhead;
    }

    void pushBack(const T& value)
    {
        ShareNodePtr p = std::make_shared<MySigListNode>(value);

        if (mHead == nullptr)
        {
            mHead = p;
            return;
        }

        ShareNodePtr iter = mHead;
        while (iter->mNext != nullptr)
        {
            iter = iter->mNext;
        }

        iter->mNext = p;
        p->mNext = nullptr;
        mSize++;
    }

private:
    class MySigListNode
    {
    public:
        MySigListNode(const T& value) : mValue(value) {}
        T mValue;
        ShareNodePtr mNext;
    };

    ShareNodePtr mHead;
    long long mSize = 0;
};


#endif // MYLIST_H
