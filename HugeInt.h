#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>

struct Node {
	short number;
	Node* next;
	Node* prev;
};

class HugeInt {

	friend std::ostream& operator<<(std::ostream&, HugeInt&);

public:

	HugeInt(long long = 0);
	HugeInt(const char*);
	~HugeInt();
	HugeInt& operator+(HugeInt&);
private:
	int count;
	Node* begin_p;
	Node* end_p;
};
#endif // !HUGEINT_H
