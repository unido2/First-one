#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;

enum Repeat{no,yes};
Repeat acc_repeat;

struct Account{
	int ac_num;
	char name[10];
	float balance;
};

void print_missing_account(ifstream&, ifstream&);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	fstream new_file("newmast.dat", ios::out | ios::in);
	ifstream old("oldmast.dat", ios::in);
	ifstream trans("trans.dat", ios::in);

	Account old_ac, trans_ac,new_ac,tmp;
	int count=0;
	
	/*
	while (old >> old_ac.ac_num >> old_ac.name >> old_ac.balance)
		cout << old_ac.name << endl;
		*/

	trans >> trans_ac.ac_num >> trans_ac.balance;
	old >> old_ac.ac_num >> old_ac.name >> old_ac.balance;


	while (!old.eof()) {
		acc_repeat = no;

		while (!trans.eof()) {
			if (trans_ac.ac_num == old_ac.ac_num) {
				if (acc_repeat == no) {
					cout << "ac_num" << trans_ac.ac_num << endl;
					new_file << old_ac.ac_num << ' '
						<< old_ac.name << ' ' 
						<< (old_ac.balance + trans_ac.balance) << endl;
					acc_repeat = yes;
					count++;
				}
				else {
					count--;
					fstream temp("temp.dat", ios::out | ios::in);
					temp.clear();
					temp.seekp(0);
					new_file.seekg(0);
					while (count != 0) {
						new_file >> tmp.ac_num >> tmp.name
							>> tmp.balance;
						
						temp << tmp.ac_num << ' ' << tmp.name << ' '
							<< tmp.balance << endl;
						count--;
					}
					
					new_file >> tmp.ac_num >> tmp.name
						>> tmp.balance;
					temp << tmp.ac_num << ' ' << tmp.name << ' '
						<< (tmp.balance+trans_ac.balance) << endl;
					
					
					new_file.seekp(0);
					temp.seekg(0);
					int i = 0;
					while (i<3) {
						temp >> tmp.ac_num >> tmp.name
							>> tmp.balance;
						cout << tmp.ac_num << ' ' << tmp.name << ' '
							<< tmp.balance<<endl;
						new_file << tmp.ac_num << ' ' << tmp.name << ' '
							<< tmp.balance << endl;
						i++;
					}
				}
			}
			trans >> trans_ac.ac_num >> trans_ac.balance;
				//break;
		}

		if (trans.eof() && acc_repeat==0) {
			new_file << old_ac.ac_num << ' '
				<< old_ac.name << ' ' << old_ac.balance << endl;
			trans.clear();
			trans.seekg(0);
			old >> old_ac.ac_num >> old_ac.name >> old_ac.balance;
			trans >> trans_ac.ac_num >> trans_ac.balance;
			count++;
		}
		else {
			trans.clear();
			trans.seekg(0);
			old >> old_ac.ac_num >> old_ac.name >> old_ac.balance;
		}
	}
	print_missing_account(old, trans);

	
	return 0;
}

void print_missing_account(ifstream& oldf, ifstream& transf)
{
	Account o, t;
	transf.clear();
	transf.seekg(0);
	oldf.clear();
	oldf.seekg(0);
	//cout << transf.tellg() << " " << oldf.tellg() << endl;

	oldf >> o.ac_num >> o.name >> o.balance;
	transf >> t.ac_num >> t.balance;

	while (!transf.eof()) {
		while (!oldf.eof()) {
			if (t.ac_num == o.ac_num)
				break;
			else
				oldf >> o.ac_num >> o.name >> o.balance;
		}
		if (oldf.eof())
			cout << "Account# " << t.ac_num << " doesn't exist" << endl;
		oldf.clear();
		oldf.seekg(0);
		transf >> t.ac_num >> t.balance;
	}
}
