#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Date1.h"

using namespace std;

int Date::days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date(int m, int d, int y) { setDate(m, d, y); }

void Date::setDate(int mm, int dd, int yy)
{
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

Date Date::operator++()
{
	helpIncrement();
	return *this;
}

Date Date::operator++(int)
{
	Date temp = *this;
	helpIncrement();
	return temp;
}

const Date& Date::operator+=(int additionalDays)
{
	for (int i = 1; i <= additionalDays; i++)
		helpIncrement();
	return *this;
}

int Date::leapYear(int y)
{
	if (y % 400 == 0 || (y % 100 != 0 && y == 0))
		return 1;
	else
		return 0;
}

int Date::endOfMonth(int d)
{
	if (month == 2 && leapYear(year))
		return d == 29;
	else
		return d==days[month];
}

void Date::helpIncrement()
{
	if (endOfMonth(day) && month == 12) {
		day = 1;
		month = 1;
		++year;
	}
	else if (endOfMonth(day)) {
		day = 1;
		++month;
	}
	else
		++day;

}

void Date::printF1() const {
	cout << (day>=10 ?"": "0") << day << " " << year << endl;
}

Date &Date::printF2() {
	cout << (month>=10 ? "" : "0")<<month
		<<"/"<<(day >=10 ? "" : "0")<<day << "/" 
		<< (year%100>=10?"":"0")<< year % 100 << endl;
	return *this;
}

Date &Date::printF3() {
	cout << monthName[month-1] <<" "<< (day % 10 < 0 ? "0" : "")
		<< day << ", " << year << endl;
	return *this;
}
