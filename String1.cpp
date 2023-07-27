#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<assert.h>
#include "String1.h"

using namespace std;


String::String(const char* s):co(0)
{
	//if (CheckArray()) {
		length = strlen(s);
		sPtr = new char[length + 1];
		assert(sPtr != 0);
		strcpy(sPtr, s);
		a[co] = sPtr;
		cout << "0-" << a[co] << " co= " << co << endl;
	//}
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
	
	if (CheckArray()) {
		cout << "coo= " << co << " co2=" << right.co << endl;
		cout << "a[co-1]= " << a[co - 1] << " right.a[right.co]= " << right.a[right.co] << endl;
		for (int i = 0; right.a[i] != NULL; i++)
			a[co + i] = right.a[i];
	}
	
	return *this;
}

const char* String::operator[](int sub)
{
	assert(sub >= 0 && sub < 5 && a[sub]!=NULL);

	return a[sub];
}

const char* String::operator[](char symb)
{
	//'m' - search max const char in array
	if (symb == 'x') {
		maxPtr = a[0];
		for (int i = 1; a[i] != NULL; i++)
			if (strcmp(a[i], maxPtr)>0)
				maxPtr = a[i];
		return maxPtr;
	}
	else
		if (symb == 'n') {
			minPtr = a[0];
			for (int i = 1; a[i] != NULL; i++)
				if (strcmp(a[i], minPtr) < 0)
					minPtr = a[i];
			return minPtr;
		}
		else
			cout << "vvedite norm symbol" << endl;

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


int String::GetCount()
{
	return co++;
}

bool String::CheckArray()
{
	for (int i = co; i < 5; i++) {
		if (a[i] == NULL || a[i]=="")
			return true;
		else GetCount();
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	for (int i = 0; s.a[i]!=NULL; i++) {
	
		out << s.a[i]<<" ";
		
	}
	
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	char temp[100];

	in >> setw(100) >> temp;
	s = temp;

	return in;
}
