#include "userTypes.h"
#include <cstring>

cMyString::cMyString(const char* pData)
{
	int strLength;
	m_pData = new char[strLength = strlen(pData) + 1];

	strncpy(m_pData, pData, strLength);
}

cMyString::cMyString(const cMyString& str)
{
	int strLength;
	m_pData = new char[strLength = strlen(str.m_pData) + 1];

	strncpy(m_pData, str.m_pData, strLength);
}


cMyString& cMyString::operator = (cMyString& str)
{
	if (this != &str)
	{
		cMyString tmpStr(str);
		char* tmpPdata = tmpStr.m_pData;
		tmpStr.m_pData = m_pData;
		m_pData = tmpPdata;
	}

	return *this;
}


char* cMyString::getData()
{
	return m_pData;
}


cMyString::~cMyString()
{
	if (m_pData != nullptr)
		delete	[]m_pData;
}

