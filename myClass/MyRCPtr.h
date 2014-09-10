#ifndef MYRCPTR_H
#define MYRCPTR_H

// T must inherit from RCObject
template<typename T>
class MyRCPtr
{
public:
    MyRCPtr(T* realPtr = nullptr) : mPtr(realPtr)
    {
        init();
    }

    MyRCPtr(const MyRCPtr& rhs) : mPtr(rhs.mPtr)
    {
        init();
    }

    MyRCPtr& operator = (const MyRCPtr& rhs)
    {
        if (mPtr != rhs.mPtr)
        {
            if (mPtr != nullptr)
            {
                mPtr->removeReference();
            }

            mPtr = rhs.mPtr;
            init();
        }

        return *this;
    }

    ~MyRCPtr()
    {
        if (mPtr != nullptr)
        {
            mPtr->removeReference();
        }
    }

    T* operator -> () const
    {
        return mPtr;
    }

    T& operator * () const
    {
        return *mPtr;
    }

private:
    T* mPtr = nullptr;

    void init()
    {
        if (mPtr == nullptr)
            return;

        if (mPtr->isShareable() == false)
        {
            mPtr = new T(*mPtr);
        }

        mPtr->addReference();
    }

};


#endif // MYRCPTR_H
