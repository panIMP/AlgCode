#ifndef USERT_TYPES_H
#define USERT_TYPES_H

#include <iostream>
#include <typeinfo>



class A
{
private:
	int value;

public:
	A(int n) { this->value = n; }
	A(const A& another) { value = another.value; }

	void print() { std::cout << value << std::endl; }
};



template <typename T>
class B
{
public:
	B() {}

	B(const B& b)
	{
        std::cout << "B(B&b)" << std::endl;
	}

	template <typename T2>
	B(const B<T2>& b)
	{
        std::cout << typeid(T).name() << std::endl;
        std::cout << typeid(T2).name() << std::endl;
        std::cout << "B(const B<T2>& b)" << std::endl;
	}
};


class cMyString
{
public:
	cMyString(const char* pData = NULL);
	cMyString(const cMyString& str);
	~cMyString(void);
	cMyString& operator = (cMyString& str);

	char* getData();

private:
	char* m_pData;
};




#endif
