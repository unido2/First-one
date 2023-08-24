#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<assert.h>
#include "String.h"

using namespace std;

String::String(const char* s)
{
	cout << "Convert constructor: " << s << endl;
	length = strlen(s);
	sPtr = new char[length + 1];
	assert(sPtr != 0);
	strcpy(sPtr, s);
}

String::String(const String& copy)
{
	cout << "Copy constructor: " << copy.sPtr  << endl;
	length = copy.length;
	sPtr = new char[length+1];
	assert(sPtr != 0);
	strcpy(sPtr, copy.sPtr);
}

String::~String()
{
	cout << "Destructor: " << sPtr << endl;
	delete[] sPtr;
}

const String& String::operator=(const String&right)
{
	cout << "Call operator ="<<endl;
	if (&right != this) {
		delete[] sPtr;
		length = right.length;
		sPtr = new char[length + 1];
		assert(sPtr != 0);
		strcpy(sPtr, right.sPtr);
	}
	else
		cout << "Attempt to assign themself" << endl;

	return *this;
}

String& String::operator+=(const String& right)
{
	char* tempPtr = sPtr;
	length += right.length;
	sPtr = new char[length+1];
	assert(sPtr != 0);
	strcpy(sPtr, tempPtr);
	strcat(sPtr, right.sPtr);
	delete[] tempPtr;

	return *this;
}

int String::operator!() const { return length==0; }

int String::operator==(const String& right) const
{
	return strcmp(sPtr, right.sPtr)==0;
}

int String::operator!=(const String& right) const
{
	return strcmp(sPtr, right.sPtr) != 0;
}

int String::operator<(const String& right) const
{
	return strcmp(sPtr, right.sPtr) <0;
}

int String::operator>(const String& right) const
{
	return strcmp(sPtr, right.sPtr) >0;
}

int String::operator>=(const String& right) const
{
	return strcmp(sPtr, right.sPtr) >= 0;
}

int String::operator<=(const String& right) const
{
	return strcmp(sPtr, right.sPtr) <= 0;
}

char& String::operator[](int sub)
{
	if (sub < 0 || sub >= length)
		throw "You are requesting string[> i <] char that is out of its limits";

	return sPtr[sub];
}

String String::operator()(int index, int subLength)
{
	assert(index >= 0 && index < length && subLength >= 0);

	String sub;

	if ((subLength == 0) || (index + subLength > length))
		sub.length = length - index + 1;
	else
		sub.length = subLength + 1;

	delete sub.sPtr;
	sub.sPtr = new char[sub.length];
	assert(sub.sPtr != 0);
	strncpy(sub.sPtr, &sPtr[index], sub.length);
	sub.sPtr[sub.length-1] = '\0';

	return sub;
}

int String::getLength() const { return length; }

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.sPtr;
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	char temp[100];

	in >> setw(100) >> temp;
	s = temp;

	return in;
}
