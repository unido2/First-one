// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int y=1;
	double emkost=0, rashod, dist, av_rash=0 ;
		 
	for (y; y>0; y++) {
		cout << "Vvedite rashod topliva (ili -1 dlya vyhoda): ";
		cin >> rashod;
		if (rashod != EOF) {
			cout << "Vvedite proydenniy put': ";
			cin >> dist;
			emkost = dist / rashod;
			cout << "Dlya etoy emkosti mile/galon: " << emkost << endl << endl;
			av_rash += emkost;
		}
		else {
			--y;
			break;
		}
	}
	cout <<endl << "Sredniy rashod benzina: " << av_rash/y << endl;
	return 0;
}
