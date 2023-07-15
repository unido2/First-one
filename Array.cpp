#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include "Array.h"


int Array::arrayCount = 0;

Array::Array(int arraySize)
{
	++arrayCount;
	size = arraySize;
	ptr = new int[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

Array::Array(const Array& copy)
{
	++arrayCount;
	size = copy.size;
	ptr = new int[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = copy.ptr[i];
}

Array::~Array()
{
	--arrayCount;
	delete[] ptr;
}

int Array::getSize() const{return size;}

const Array& Array::operator=(const Array& rightAr)
{
	if (this != &rightAr) {
		delete[] ptr;
		size = rightAr.size;
		ptr = new int[size];
		assert(ptr != 0);

		for (int i = 0; i < size; i++)
			ptr[i] = rightAr.ptr[i];
	}
	return *this;
}

Array& Array::operator+(Array& ar)
{
	assert(size == ar.size && "To sum arrays must be equal size");
	for (int i = 0; i < size; i++)
		ptr[i] = ptr[i]+ ar.ptr[i];

	return *this;
}

int Array::operator==(const Array& right)
{
	if (size != right.size)
		return 0;
	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return 0;

	return 1;
}

int Array::operator!=(const Array& right)
{
	if (size != right.size)
		return 1;
	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return 1;

	return 0;
}

int& Array::operator[](int sub)
{
	assert(sub >= 0 && sub < size);
	return ptr[sub];
}

int Array::getArrayCount(){return arrayCount;}

std::istream& operator>>(std::istream& input, Array& a) {

	for (int i = 0; i < a.size;i++) 
		input >> a.ptr[i];
	return input;
}

std::ostream& operator<<(std::ostream& out, const Array& a)
{
	int i;
	for (i = 0; i < a.size; i++) {
		out << a.ptr[i] << " ";
		if ((i + 1) % 10 == 0)
			out << std::endl;
	}
	if(i%10!=0)
	out << std::endl;

	return out;
}

