#ifndef DATE1_H
#define DATE1_H

#include<iostream>

class Date {
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date(int m=1,int d=1, int y=1900);
	
	~Date();

	void printF1() const;
	void printF2()const;
	void printF3() const;

private:
	int day, month, year;
	static int days[];
	
	void helpIncrement();
};
#endif // !DATE1_H

