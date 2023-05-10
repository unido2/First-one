
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void func1(int[],int);


int main() {

	const int s_sellers = 5,s_products=6, s_month=2;
	int total_p = 0, total_s = 0;
	int sales[s_products][s_sellers] = { 0 };
	int sell1_d1[s_products] = { 0,30,55,21,0,35 },
		sell1_d2[s_products] = { 0,22,30,15,3,10 };

	
	for (int i = 1; i < s_products; i++) {
		
		sales[i][1] += sell1_d1[i]+sell1_d2[i];
		sales[i][2] += sell1_d1[i] + 5;
		sales[i][3] += sell1_d1[i] + 6;
		sales[i][4] += sell1_d1[i] + 7;
	}
	cout << setw(11) << "s1" << "   " << "s2" << "   "
		<< "s3" << "   " << "s4" << endl;
		cout << setw(7) <<" " << "--------------------" << endl;

	for (int i = 1; i < s_products; i++) {
		cout <<setw(6)<< "prod" << i<<"|";
		for (int j = 1; j < s_sellers; j++) {
			cout << setw(3) << sales[i][j] << "  ";
			total_p += sales[i][j];
		}
		cout << "total: " << total_p << endl;
		total_p = 0;
	}
	cout << setw(7) << " " << "--------------------" << endl;
	cout << "total_s" << "|";
	for (int j = 1; j < s_sellers; j++) {
		for (int i = 1; i < s_products; i++)
			total_s += sales[i][j];
		cout << total_s << "  ";
		total_s = 0;
	}

	return 0;
}




