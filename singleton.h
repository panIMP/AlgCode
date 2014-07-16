#pragma once
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

