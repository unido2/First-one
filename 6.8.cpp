#include <iostream>
#include "TIME3.h"

using namespace std;

void incrementMinutes(Time& tt, int count);

int main() {
	

	Time t;
	t.setHour(12);
	t.setMinute(59);
	t.setSecond(50);
	cout << endl;

// driver
	while (t.getHour() != 13 || t.getMinute() != 1) {
		t.tick();
		t.printStandard();
		cout<<((t.getSecond() % 5 == 0) ? '\n' : '\t');
	}

	return 0;
}

void incrementMinutes(Time& tt, int count) {
	cout << "Uvelichenie minute na" << count << endl
		<< "Nachal'noe vremya: ";
	tt.printStandard();

	for (int i = 1; i <= count; i++) {
		tt.setMinute((tt.getMinute() + 1) % 60);
		if (tt.getMinute() == 0)
			tt.setHour((tt.getHour() + 1) % 24);
		cout << endl<<"minuty+1: ";
		tt.printStandard();
	}
	cout << endl;
}