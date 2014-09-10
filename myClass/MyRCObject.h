#ifndef MYRCOBJECT_H
#define MYRCOBJECT_H

class MyRCObject
{
public:
    MyRCObject()
    {
        refCount = 0;
        shareable = true;
    }

    MyRCObject(const MyRCObject& rhs)
    {
        refCount = 0;
        shareable = true;
    }

    MyRCObject& operator = (const MyRCObject& rhs)
    {
        return *this;
    }

    virtual ~MyRCObject() {}

    void addReference()
    {
        ++refCount;
    }

    void removeReference()
    {
        if(--refCount == 0)
            delete this;
    }

    void markUnshareable()
    {
        shareable = false;
    }

    bool isShareable() const
    {
        return shareable;
    }

    bool isShared() const
    {
        return (refCount > 1);
    }

private:
    int refCount;
    bool shareable;
};

#endif // MYRCOBJECT_H
