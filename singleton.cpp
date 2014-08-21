#include <iostream>

#include <mutex>


class Singleton
{
public:
	static Singleton* getInstance();

private:
	static Singleton* m_pInstance;
	static std::mutex m_nLockGetInstance;

protected:
	Singleton();


};


Singleton* Singleton::m_pInstance = nullptr;
std::mutex Singleton::m_nLockGetInstance;

Singleton::Singleton()
{
	std::cout << "single instance has been created!";
}

Singleton* Singleton::getInstance()
{
	if (m_pInstance == nullptr)
	{
		m_nLockGetInstance.lock();
		
		if (m_pInstance == nullptr)
			m_pInstance = new Singleton();

		m_nLockGetInstance.unlock();
	}

	return m_pInstance;
}

