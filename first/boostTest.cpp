#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


class base
{
public:
    base(double pri, double dis) : priceVal(pri), discount(dis) {}
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
    deBase(double pri, double dis, double newDis) : base(pri, dis), newDiscount(newDis) {}
    deBase() = default;

    void price2(double name)
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


int main()
{
    base a(100, 0.3);
    deBase b(200, 0.4, 0.5);
    deBase c;

    int k = 23;
    int val = k;

    a.price();
    a.price(21);
    b.price(22);
    b.price(val);

    return 0;
}
