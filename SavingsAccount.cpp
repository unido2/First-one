#include<iostream>
#include<iomanip>
#include "SavingsAccount.h"


double SavingsAccount::annualInteresRate = 0;

SavingsAccount::SavingsAccount(double bal) {
	
	int b = (int)(bal * 1000) % 10;
	
	if (b == 0 && bal > 0) {
		savingsBalance = bal;
	}
	else {
		savingsBalance = 0;
		std::cout << "Wrong deposit! Balance is set to 0$" << std::endl;
	}
	calculateMonthlyInterest();
}

void SavingsAccount::modifyInterestRate(int newRate)
{
	annualInteresRate = newRate;
}

 void SavingsAccount::printSavings() const {

	std::cout << "Rate: " <<std::fixed
		<< std::setprecision(1)<< annualInteresRate<<"%" << std::endl;
	std::cout << "Balance: " << std::fixed 
	<< std::setprecision(2) << savingsBalance << " $" << std::endl;

}

 SavingsAccount& SavingsAccount::calculateMonthlyInterest()
{	
	//std::cout << savingsBalance << std::endl;
	savingsBalance +=(savingsBalance * annualInteresRate/100 / 12);
	return *this;
}
