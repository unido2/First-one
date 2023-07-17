#ifndef DATE1_H
#define DATE1_H

#include<iostream>

class Date {
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	Date(int m=1,int d=1, int y=1900);
	void setDate(int, int, int);
	Date operator++();
	Date operator++(int);
	const Date& operator+=(int);

	int leapYear(int);
	int endOfMonth(int);
	
private:
	int day, month, year;
	static int days[];
	
	void helpIncrement();
};
#endif // !DATE1_H

