#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mSort (const char *[], const int*, int (*)(const char*,const char*));
int vozr(const char*, const char*);
int ubyv(const char*, const char*);

int main() {
	setlocale(LC_ALL, "");

	const int size = 10;
	const char* massy[size] = { "Kyiv","Donetsk","Dnepr","Zaporizhzhia",
	"Lviv","Kherson","Ternopil","Rivno","Belaya Cerkov'","Cherkassy"};
	int vari;
	cout << "1-dla po vozrastaniyu(s nachala), 2 - dlya po ubyvaniyu" << endl;
	cin >> vari;
	if (vari == 1)
		mSort(massy, &size, vozr);
	else
		mSort(massy, &size, ubyv);
	
	return 0;
}

void mSort(const char* base[], const int* size, int (*yoy)(const char*,const char*)) {

	const char *hold=base[0];
	
	for(int j=1;j<=*size-1;j++)
	for (int i = 0; i < *size-1; i++) {
		if ((*yoy)(base[i], base[i + 1])) {
			hold = base[i];
			base[i] = base[i + 1];
			base[i + 1] = hold;
		}
	}
	for (int j = 0; j < *size; j++)
		cout << base[j] << endl;
}

int vozr(const char* b1, const char* b2) {
	return strcmp(b1, b2) > 0;
}

int ubyv(const char* b1, const char* b2) {
	return strcmp(b1, b2) < 0;
}