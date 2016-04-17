#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <stdio.h>
#include <string.h>

class MyString
{
public:
	MyString();
	MyString(char* string);
	//MyString(MyString& string);
	virtual ~MyString();
	
	//MyString substr(int index,int length);
	//int find(const MyString& str, int index = 0);
	//char& at(int loc);
	//void swap(MyString& from);
	
	int getLength();
	bool isEmpty();
	char* c_str();
	void set_data(char *input, MyString &S);

	//friend bool operator == (const MyString & S1, const MyString & S2);
	//friend bool operator < (const MyString & S1, const MyString & S2);
	//friend bool operator > (const MyString & S1, const MyString & S2);
	//friend MyString operator +(MyString &S1 , MyString & S2);

protected:
private:
	unsigned int m_length;
	char *m_data;

};
//ostream& operator <<(ostream& OS, MyString &S);
//istream& operator >>(istream& IS, MyString &S);

#endif //__MYSTRING_H__