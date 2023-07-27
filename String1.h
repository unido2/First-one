#ifndef STRING_H
#define STRING_H
#include<iostream>
class String {
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
public:
	String(const char * = "");
	String(const String&);
	~String();
	const String& operator=(const String&);
	String& operator += (const String&);

	int operator!() const;
	int operator==(const String&) const;
	int operator!=(const String&) const;
	int operator<(const String&) const;
	int operator>(const String&) const;
	int operator>=(const String&) const;
	int operator<=(const String&) const;
	const char* operator[](int);
	const char* operator[](char);
	String operator()(int, int);
	int getLength() const;

private:
	const char* a[5] = {};
	const char* maxPtr;
	const char* minPtr;
	char* sPtr;
	int length;
	int co;

	int GetCount();
	bool CheckArray();
};

#endif // !STRING_H
