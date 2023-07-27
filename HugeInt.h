#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>
class HugeInt {
	friend std::ostream& operator<<(std::ostream&, HugeInt&);
public:
	HugeInt(long = 0);
	HugeInt(const char*);
	HugeInt operator+(HugeInt&);
private:
	short integer[30];

};

#endif // !HUGEINT_H
