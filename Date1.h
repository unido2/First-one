#ifndef DATE1_H
#define DATE1_H
class Date {
public:
	Date();
	Date(int, int, int);
	Date(const char*, int, int);
	static int getCount();
	
	~Date();

	void printF1() const;
	void printF2()const;
	void printF3() const;

private:
	int day, month, year;
	static int count;
	const char** monthName;

	int checkDay(int);
};
#endif // !DATE1_H

