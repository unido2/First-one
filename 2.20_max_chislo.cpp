// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int passes=0,failures=0,student=1,result;

	while (student <= 10) {
		cout << "Vvedite resul'tat (1-sdal, 2-ne sdal): "
			<< endl;
		cin >> result;
		
		if (result == 1 || result == 2) {
			if (result == 1)
				++passes;
			else
				++failures;
			student++;
		}
		else
			cout << "Ne vernoe znachenie,vvedite 1 ili 2" << endl << endl;
	}
	cout << "Sdali  " << passes << endl 
		 << "Ne sdali  " << failures << endl;
	return 0;
}
