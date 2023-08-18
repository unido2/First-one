
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<iomanip>

template<class T, int number>
class Array;

template<class T, int number>
std::ostream& operator<<(std::ostream& out, const Array<T, number>& a);

template<class T, int number>
std::istream& operator>>(std::istream& input, const Array<T, number>& a);


template<class T, int number>
class Array {
	friend std::ostream& operator<< <>(std::ostream& out, const Array<T, number>& a);
	friend std::istream& operator>> <>(std::istream& input, const Array<T, number>& a);
public:
	Array();
	Array(const Array&);
	~Array();
	int getSize() const;

	T& operator=(const T);
	const Array& operator=(const Array&);
	Array& operator+(Array&);
	
	int operator==(const Array&);
	int operator!=(const Array&);



	T &operator[](int);
	static int getArrayCount();

private:
	T* ptr;
	int size;
	static int arrayCount;
};

#endif // !ARRAY_H


template<class T, int number>
int Array<T, number> ::arrayCount = 0;


template<class T, int number>
Array<T, number>::Array()
{
	++arrayCount;
	size = number;
	ptr = new T[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

template<class T, int number>
Array<T, number>::Array(const Array<T,number>& copy)
{
	++arrayCount;
	size = copy.size;
	ptr = new T[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = copy.ptr[i];
}
template<class T, int number>
Array<T, number>::~Array()
{
	--arrayCount;
	delete[] ptr;
}

template<class T, int number>
int Array<T, number>::getSize() const { return size; }


template<class T, int number>
T& Array<T, number>::operator=(const T right)
{
	return *this = right;
}

template<class T, int number>
const Array<T, number>& Array<T, number>::operator=(const Array<T, number>& rightAr)
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
template<class T, int number>
Array<T, number>& Array<T, number>::operator+(Array& ar)
{
	assert(size == ar.size && "To sum arrays must be equal size");
	for (int i = 0; i < size; i++)
		ptr[i] = ptr[i] + ar.ptr[i];

	return *this;
}

template<class T, int number>
int Array<T, number>::operator==(const Array& right)
{
	if (size != right.size)
		return 0;
	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return 0;

	return 1;
}

template<class T, int number>
int Array<T, number>::operator!=(const Array& right)
{
	

	return (*this==right? 0:1);
}

template<class T, int number>
T& Array<T, number>::operator[](int sub)
{
	assert(sub >= 0 && sub < size);

	return ptr[sub];
}

template<class T, int number>
int Array<T, number>::getArrayCount() { return arrayCount; }


template<class T, int number>
std::istream& operator>>(std::istream& input, const Array<T, number>& a) {

	for (int i = 0; i < a.size; i++)
		input >> a.ptr[i];
	return input;
}

template<class T, int number>
std::ostream& operator<<(std::ostream& out, const Array<T, number>& a)
{
	int i;
	for (i = 0; i < a.size; i++) {
		out <<std::setiosflags(std::ios::left)<<std::setw(3)<< a.ptr[i];
		if ((i + 1) % 10 == 0)
			out << std::endl;
	}
	if (i % 10 != 0)
		out << std::endl;

	return out;
}
