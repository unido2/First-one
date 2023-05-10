// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int umnog(int,int);

 int main()
 {
	 int e1,e2,a,b, c,res, lose=0,win=0;

	 srand(time(NULL));
	
	 cout << "Vvedite uroven' slognosti:" << endl
		 << "1 - odnorazr chisla"<<endl
		 << "2 - dvurazryanye chisla"<<endl;
	 cin >> e1;
	 cout << "Vvedite operaciyu s chislami:" << endl
		 << "1 - slogenie" << endl
		 << "2 - vychitanie" << endl
		 << "3 - umnogenie" << endl
		 << "2 - delenie" << endl;
	 cin >> e2;

	 a=umnog(e1,e2);

	 for (int i = 1; i >= 0; i++) {
		 cin >> c;
		 if (c == a) {
			 cout << "you win" << endl;
			 win++;
			 a = umnog(e1,e2);
		 }
		 else {
			 cout << "You lose, try again" << endl;
			 lose++;
		 }
		 if (i == 10) {
			 res = win * 10;
			 if (res < 75) {
				 cout << "Obratites' k uchitelyu!" << endl;
				 break;
			 }
		 }
	 }
	 return 0;
}

int umnog(int e1, int e2) {
	
	 int a, b;
	 switch(e1) {
		case 1:
		 a = 1 + rand() % 9;
		 b = 1 + rand() % 9;
		 break;
		 case 2:
		 a = 1 + rand() % 99;
		 b = 1 + rand() % 99;
	 }
	 switch (e2) {
	 case 1:
		 cout << "Skol'ko budet " << a << " + " << b << endl;
		 return a + b;
		 break;
	 case 2:
		 cout << "Skol'ko budet " << a << " - " << b << endl;
		 return a - b;
		 break;
	 case 3:
		 cout << "Skol'ko budet " << a << " * " << b << endl;
		 return a * b;
		 break;
	 case 4:
		 cout << "Skol'ko budet " << a << " / " << b << endl;
		 return a / b;
		 break;
	 }
	 
 }

 



