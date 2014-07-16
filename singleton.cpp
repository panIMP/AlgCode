#include "singleton.h"
#include <iostream>


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

