#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <myClass/MyString.h>

using namespace std;


class base
{
public:
    base(double pri, double dis = 0.11) : priceVal(pri), discount(dis) {}
    base() = default;

    void price(int test)
    {
        cout << test << endl;
    }

    void price(char* name = "nothing")
    {
        cout << name << endl;
        cout << priceVal << endl;
    }

    virtual void dist()
    {
        cout << discount << endl;
    }

    virtual ~base() = default;

protected:
    void sale_price()
    {
        cout << (priceVal * discount) << endl;
    }

protected:
    double priceVal;
    double discount;
};


class deBase : public base
{
public:
    using base::base;
    //deBase(double pri, double dis, double newDis) : base(pri, dis), newDiscount(newDis) {}

    virtual void price2(double name)
    {
        cout << name << endl;
        cout << priceVal << endl;
    }

    ~deBase() = default;

protected:
    const double priceVal = 35;

private:
    double newDiscount;
    int* a;
    base* c;
};


class ddeBase : public deBase
{
public:
    using deBase::deBase;

private:
    int joke;
};


//int main()
//{
//    base a(100, 0.3);
//    deBase b(200, 0.4);
//    deBase c(201);
//    ddeBase d(300);
//    deBase f;


//    a.dist();
//    b.dist();
//    c.dist();

//    return 0;
//}
