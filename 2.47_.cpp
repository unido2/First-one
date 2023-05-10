// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
void answers(int);

 int main()
 {
	 int a, b,c,ans;
	 srand(time(NULL));
	
	 do {
		 a = 1 + rand() % 9;
		 b = 1 + rand() % 9;
		 cout << "skol'ko budet " << a << " * " << b << "?" << endl;
		 cin >> c;
		 if (a * b == c) {
			 answers(1);
		 }
		 else {
			 
			 do {
				 answers(0);
				 cin >> c;
			 } while (!(a * b == c));
			 answers(1);
		 }
	 } while (c!=EOF);
}

 void answers(int ans) {
	 int ans_i;
	 if (ans == 1) {
		 ans_i = 1 + rand() % 4;
		 switch (ans_i) {
		 case 1:
			 cout << "Very good!" << endl;
			 break;
		 case 2:
			 cout << "Uoo cool" << endl;
			 break;
		 case 3:
			 cout << "Supaa" << endl;
			 break;
		 case 4:
			 cout << "You hot!" << endl;
			 break;
		 }
	 }
	 else {
		 ans_i = 1 + rand() % 4;
		 switch (ans_i) {
		 case 1:
			 cout << "nooo" << endl;
			 break;
		 case 2:
			 cout << "baad" << endl;
			 break;
		 case 3:
			 cout << "naah" << endl;
			 break;
		 case 4:
			 cout << "you lose" << endl;
			 break;
		 }
	 }
 }

  
 



