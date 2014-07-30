#include <stdio.h>
#include <stack>
#include <exception>
#include <iostream>



using namespace std;


template <typename T> 
class staQuene
{
public:
	staQuene(void) {}
	~staQuene(void) {}

	// add a node at the end of the module quene
	void appendTail(const T& element)
	{
		stack1.push(element);
		count++;
	}
	
	// delete a node at the front of the module quene
	T deleteHead(void) 
	{
		if (stack2.size() <= 0)
		{
			while (stack1.size() > 0)
			{
				T& data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}

		if (stack2.size() == 0)
            throw std::exception();

		T& data = stack2.top();
		stack2.pop();
		count--;

		return data;
	}

	int size(void)
	{
		return count;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
	int count;
};


int stackModQueue(int argc, char* argv[])
{
	staQuene<char> quene;

	quene.appendTail('a');
	quene.appendTail('b');
	quene.appendTail('c');
	quene.appendTail('d');

	cout << quene.deleteHead() << endl;

	quene.appendTail('e');
	quene.appendTail('f');

	while (quene.size() > 0)
	{
		cout << quene.deleteHead();
	}


	return 0;
}



// a new stack type with min() operation whose time complexity is O(1)
template <typename T> 
class StackWithMin
{
public:
	StackWithMin(void) {}
	virtual ~StackWithMin(void) {}

	T& top(void)
	{
		return m_initStack.top();
	}

	const T& top(void) const
	{
		return m_initStack.top();
	}

	void pop(void)
	{
		if (m_initStack.empty() || m_assistStack.empty())
			throw ReadEmptyStack();

		m_initStack.pop();
		m_assistStack.pop();
	}

	void push(const T& node)
	{
		m_initStack.push(node);

		if (m_assistStack.size() == 0 || node < m_assistStack.top())
			m_assistStack.push(node);
		else
			m_assistStack.push(m_assistStack.top());
	}

	size_t size(void)
	{
		return m_initStack.size();
	}

	bool empty(void) const
	{
		return m_initStack.empty();
	}

	const T& min(void) const
	{
		if (m_initStack.empty() || m_assistStack.empty())
			throw ReadEmptyStack();

		return m_assistStack.top();
	}

	class ReadEmptyStack : public exception
	{
	public:
		virtual const char* what() const throw() 
		{
			return "read empty stack";
		}
	};

private:
	stack<T> m_initStack;
	stack<T> m_assistStack;	// store the min elements
};



// judge if it's a pop sequence for the push sequence when using a stack
bool isPopOrder(const int* pPush, const int* pPop, int len)
{
	if (pPush == NULL || pPop == NULL)
        throw new exception();

	bool isPossible = false;

	const int* pPushEnd = pPush + len;
	const int* pPopEnd = pPop + len;

	stack<int> stackData;

	while (pPush != pPushEnd)
	{
		stackData.push(*pPush);
		
		while (!stackData.empty() && pPop != pPopEnd)
		{
			if (stackData.top() == *pPop)
			{
				stackData.pop();
				pPop++;
			}
			else
			{
				break;
			}
		}

		pPush++;
	}

	if (pPush == pPushEnd && pPop == pPopEnd)
		isPossible = true;

	return isPossible;
}

