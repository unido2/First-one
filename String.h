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
	char& operator[](int);
	String operator()(int, int);
	int getLength() const;

private:
	char* sPtr;
	int length;
};

#endif // !STRING_H
