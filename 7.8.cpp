#include<iostream>
#include "SavingsAccount.h"

int main() {
	SavingsAccount saver1(2000);
	SavingsAccount* saver2 = new SavingsAccount(3000);


	for (int i = 0; i < 2; i++) {
		SavingsAccount::modifyInterestRate(3 + i);
		saver1.calculateMonthlyInterest().printSavings();
		saver2->calculateMonthlyInterest().printSavings();
	}
	
	delete saver2;

	return 0;
}