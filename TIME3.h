
#ifndef TIME3_H
#define TIME3_H
class Time {

public:
	Time(int=0,int=0,int=0);
	void setTime(int, int, int);

	void tick();

	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	int getHour() const;
	int getMinute() const ;
	int getSecond() const;

	void printMilitary();
	void printStandard();

private:
	int hour;
	int minute;
	int second;
};
#endif
