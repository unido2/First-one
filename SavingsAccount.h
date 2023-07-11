#pragma once
#ifndef SavingsAccount_H
#define SavingsAccount_H

class SavingsAccount {

public:
	SavingsAccount(double = 0);
	
	static void modifyInterestRate(int);
	SavingsAccount &calculateMonthlyInterest();
	void printSavings() const;

private:
	static double annualInteresRate;
	double savingsBalance;
	
};

#endif // !SavingsAccount_H
