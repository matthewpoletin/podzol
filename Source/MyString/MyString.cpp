#include "MyString.h"

MyString::MyString()
{
	m_data = NULL;
	m_length = 0;
}

 MyString::MyString(char* string)
{
	m_data = string;
	m_length = strlen(string);
}

MyString::~MyString()
{
}

int MyString::getLength()
{
	return m_length;
}

bool MyString::isEmpty()
{
	if (m_length == 0) return true;
	else return false;
}

char* MyString::c_str()
{
	return m_data;
}

void MyString::set_data(char* input, MyString & S)
{
	m_length = strlen(input) + 1;
	m_data = new char[m_length];
	memcpy(m_data, input, m_length);
}
