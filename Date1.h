#ifndef DATE1_H
#define DATE1_H
class Date {
public:
	Date();
	Date(int, int, int);
	Date(const char*, int, int);
	static int getCount();
	
	~Date();

	Date &printF1();
	Date &printF2();
	Date &printF3();

private:
	int day, month, year;
	static int count;
	const char** monthName;

	int checkDay(int);
};
#endif // !DATE1_H

