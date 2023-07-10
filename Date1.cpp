#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<time.h>
#include "Date1.h"


using namespace std;

int Date::count = 0;

int Date::getCount() {
	return count;
}

Date::Date()

{
	monthName = new const char* [12] { "January", "Feburary", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };
	
	time_t mytime = time(NULL);
	struct tm* tiime = localtime(&mytime);

	day = tiime->tm_mday;
	month = tiime->tm_mon + 1;
	year = 1900 + tiime->tm_year;

	++count;
	cout << "Constructor of object Date3" << endl;
}

//constructor 1
Date::Date(int d, int m, int y)
{
	monthName = new const char* [12] { "January", "Feburary", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };

	if (m > 0 && m <= 12)
		month = m;
	else {
		month = 1;
		cout << "Month " << m << " isn't right. Set month to 1" << endl;
	}
	if (y > 1900 && y <= 2100)
		year = y;
	else {
		year = 1;
		cout << "Year " << y << " isn't right. Set year to 1" << endl;
	}
	day = checkDay(d);

	cout << "Constructor of object Date1" << endl;
	count++;
}

//constructor 2
Date::Date(const char* m, int d, int y) {

	monthName = new const char* [12] { "January", "Feburary", "March", "April",
		"May","June","July","August","September","October","November","December" };

	int countL = 0;
	
	//zaglavnaya bukva
	char *a=new char[strlen(m)+1];
	strcpy(a, m);
	a[0]=toupper(a[0]);


	for (int i = 0; i < 12; i++) {
		if (strcmp(a,monthName[i])==0) {
			countL++;
			month = i+1;
			break;
		}
	}
	if (countL == 0) {
		month = 1;
		cout << "Month " << m << " isn't right. Set month to 1" << endl;
	}
	if (y > 1900 && y <= 2100)
		year = y;
	else {
		year = 1;
		cout << "Year " << y << " isn't right. Set year to 1" << endl;
	}
	day = checkDay(d);

	cout << "Constructor of object Date2" << endl;
	delete[] a;
	count++;
}


//DESTRUCTOR
Date::~Date() {
	
	delete[] monthName;
	--count;
	cout << "destructor done" << endl;
}

//proverka dnya
int Date::checkDay(int da) {

	int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (da > 0 && da <= daysPerMonth[month])
		return da;
	if (month == 2 && da == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return da;
	
	cout << "Day " << da << " isn't right. Set day to 1" << endl;

	return 1;
}

 Date &Date::printF1() {
	cout << (day>=10 ?"": "0") << day << " " << year << endl;
	return *this;
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

