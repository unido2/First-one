
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>


class Array {
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
public:
	Array(int = 10);
	Array(const Array&);
	~Array();
	int getSize() const;
	const Array& operator=(const Array&);
	Array& operator+(Array&);
	
	int operator==(const Array&);
	int operator!=(const Array&);



	int &operator[](int);
	static int getArrayCount();

private:
	int* ptr;

	int size;
	static int arrayCount;
};

#endif // !ARRAY_H
