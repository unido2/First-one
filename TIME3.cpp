#include <iostream>
#include "TIME3.h"
using namespace std;


Time::Time(int h, int m, int s) { setTime(h, m, s); }

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m <= 60) ? m : 0;
	second = (s >= 0 && s <= 60) ? s : 0;
}

//prirost vremrni dlya standard time
void Time::tick() {
	second=(second+1)%60;
	if (second == 0)
		minute = (minute + 1) % 60;
	if (minute == 0 && second==0)
		hour = (hour + 1) % 24;
}


void Time::setHour(int h) {
	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m) {
	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s) {
	second = (s >= 0 && s < 60) ? s : 0;
}


int Time::getHour() const {
	return hour;
}
int Time::getMinute() const {
	return minute;
}
int Time::getSecond() const {
	return second;
}


void Time::printMilitary()
{
	cout << (hour < 10 ? "0" : "") << hour << ":"
		<< (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second;
}

void Time::printStandard()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		<< ":" << (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second
		<< (hour < 12 ? "AM" : "PM");
}
