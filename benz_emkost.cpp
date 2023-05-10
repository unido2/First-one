// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int schet, y=1;
	double n_bal, s_rash, s_prih, credit, bal_credit=0 ;

	for (y; y > 0; y++) {
		cout << "Vvedite nomer scheta (-1, esli vvod zakonchen): " << endl;
		cin >> schet;
		if (schet != EOF) {
			cout << "Vvedite nach. balans:  " << endl;
			cin >> n_bal;
			cout << "Vvedite summu rashodov:  " << endl;
			cin >> s_rash;
			cout << "Vvedite summu prihoda:  " << endl;
			cin >> s_prih;
			cout << "Vvedite predel kredita:  " << endl << endl;
			cin >> credit;
			bal_credit = n_bal + s_rash - s_prih;
			if (bal_credit > credit) {
				cout << "Schet:  " << schet << endl;
				cout << "Predel kredita:  " << credit << endl;
				cout << "Balans:  " << bal_credit << endl;
				cout << "Balans credita prevychen!" << endl << endl;
			}
		}
		else
			break;
	}
return 0;
}
