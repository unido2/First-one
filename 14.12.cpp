#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;

struct Item {
	int number;
	char name[30];
	int quantity;
	float price;
};

int printMenu();
void showItems(fstream&, int);
void addNewItem(fstream&);
void deleteItem(fstream&);
void editItem(fstream&);
void printItems(fstream&);



int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	fstream file("Hoz_shop.dat", ios::out | ios::in);
	int choise;

	if (!file) {
		cerr << "File with items doesn't exist. \n Programm closed"
			<<endl;
		exit(1);
	}

	while ((choise = printMenu())!=5) {
		switch (choise) {
		case 1:
			printItems(file);
			break;
		case 2:
			addNewItem(file);
			break;
		case 3:
			editItem(file);
			break;
		case 4:
			deleteItem(file);
			break;
		default:
			cerr << "Incorrect menu number" << endl;
		}
		file.clear();
		file.seekg(0);
	}
	cerr << "Programm closed" << endl;

	return 0;
}

int printMenu()
{
	int menuChoose;
	cout << "Choose action:" << endl
		<< "1 - print existed items to .txt file" << endl
		<< "2 - add new item" << endl
		<< "3 - edit item" << endl
		<< "4 - delete item" << endl
		<< "5 - close programm" << endl
		<< "? ";
	cin >> menuChoose;
	return menuChoose;
}


void showItems(fstream& f,int itemNo)/*0 - print all, otherwise print exact item*/
{
	Item it;

	f.clear();
	f.seekg(0);
	cout << endl;
	cout << setiosflags(ios::left) << setw(10) << "Item #"
		<< setw(15) << "Name"<<setiosflags(ios::right)
		<< setw(10) << "Quantity"
		<< setw(10) << "Price"
		<< resetiosflags(ios::right) << endl;

	if (itemNo != 0) {
		f.seekg(sizeof(it) * (itemNo - 1));
		f.read((char*)&it, sizeof(it));
		cout << setiosflags(ios::left) << setw(10) << it.number
			<< setw(15) << it.name
			<< setiosflags(ios::right) << setw(10) << it.quantity
			<< setiosflags(ios::fixed)
			<< setprecision(2) << setw(10) << it.price 
			<<resetiosflags(ios::right)<< endl;
		f.read((char*)&it, sizeof(it));
	}
	else {
		int count = 0;
		f.seekg(0);
		f.read((char*)&it, sizeof(it));
		while (!f.eof()) {
			if (it.number != 0) {
				count++;
				cout << setiosflags(ios::left) << setw(10) << it.number
					<< setw(15) << it.name
					<< setiosflags(ios::right) << setw(10) << it.quantity
					<< setiosflags(ios::fixed)
					<< setprecision(2) << setw(10) << it.price
					<< resetiosflags(ios::right) << endl;
			}
			f.read((char*)&it, sizeof(it));
		}
		if (count == 0)
			cout <<setiosflags(ios::right)<<setw(35) << "There are none exist items" 
			<< endl;
	}
	cout << resetiosflags(ios::right)<<endl;
		f.clear();
		f.seekg(0);
}

void addNewItem(fstream& f)
{
	int item_no;
	showItems(f, 0);
	cout << "Enter item number to add (1-100): ? ";
	cin >> item_no;
	while (item_no < 1 || item_no>100) {
		cout << "Enter correct number : ";
		cin >> item_no;
	}
	Item it;
	f.seekg(sizeof(it) * (item_no - 1));
	f.read((char*)&it, sizeof(it));
	if (it.number == 0) {
		cout << "Enter item name, quantity, price:" << endl;
		cin >> it.name >> it.quantity >> it.price;
		it.number = item_no;
		f.seekp(sizeof(it) * (item_no - 1));
		f.write((char*)&it, sizeof(it));
		showItems(f, item_no);
	}
	else
		cout << "Item "<< item_no<< " already exist" << endl;
}

void deleteItem(fstream& f)
{
	int item_no;
	showItems(f, 0);
	cout << "Enter item number to delete (see above^): ? ";
	cin >> item_no;
	while (item_no < 1 || item_no>100) {
		cout << "Enter correct number : ";
		cin >> item_no;
	}
	Item it;
	Item blank = { 0,"",0,0 };

	f.seekg(sizeof(it) * (item_no - 1));
	f.read((char*)&it, sizeof(it));
	if (it.number != 0) {
		f.seekp(sizeof(it) * (item_no - 1));
		f.write((char*)&blank, sizeof(it));
		cout << "Item " << item_no << " is deleted" << endl;
	}
	else
		cout << "Item " << item_no << " inst't exist" << endl;
}

void editItem(fstream& f)
{
	int subMenuEditItem();
	
	int item_no;
	showItems(f, 0);
	cout << "Enter item number to edit (see above^): ? ";
	cin >> item_no;
	while (item_no < 1 || item_no>100) {
		cout << "Enter correct number : ";
		cin >> item_no;
	}

	Item it;
	f.seekg(sizeof(it) * (item_no - 1));
	f.read((char*)&it, sizeof(it));

	if (it.number == item_no) {
		int choise;
		while ((choise = subMenuEditItem()) != 4) {
			switch (choise) {
			case 1:
				cout << "Enter new name: ? ";
				cin >> it.name;
				f.seekp(sizeof(it) * (item_no - 1));
				f.write((char*)&it, sizeof(it));
				break;
			case 2:
				cout << "Enter new quantity: ? ";
				cin >> it.quantity;
				f.seekp(sizeof(it) * (item_no - 1));
				f.write((char*)&it, sizeof(it));
				break;
			case 3:
				cout << "Enter new price: ? ";
				cin >> it.price;
				f.seekp(sizeof(it) * (item_no - 1));
				f.write((char*)&it, sizeof(it));
				break;
			default:
				cerr << "Incorrect menu choise" << endl;
			}
			f.seekg(sizeof(it) * (item_no - 1));
			f.read((char*)&it, sizeof(it));
		}
		showItems(f, item_no);
	}
	else
		cout << "Item " << item_no << " inst't exist" << endl;
}



int subMenuEditItem()
{
	int subMenuChoise;
	cout << "Choose what you want to edit:"<<endl
		<< "1 - item name" << endl
		<< "2 - quantity of items" << endl
		<< "3 - item price" << endl
		<< "4 - exit to main menu" << endl
		<< "? ";
	cin >> subMenuChoise;

	return subMenuChoise;
}

void printItems(fstream& f)
{
	ofstream fPrint("print_hoz_shop.txt", ios::out);

	if (!fPrint) {
		cerr << "File cant't be open" << endl;
		exit(1);
	}
	cout << "Items save to \"print_hoz_shop.txt\" file" << endl<<endl;

	fPrint << setiosflags(ios::left) << setw(10) << "Item #"
		<< setw(15) << "Name" << setiosflags(ios::right)
		<< setw(10) << "Quantity"
		<< setw(10) << "Price"
		<< resetiosflags(ios::right) << endl;

	f.seekg(0);
	Item it;
	f.read((char*)&it, sizeof(it));
	while (!f.eof()) {
		if (it.number != 0) {
			fPrint << setiosflags(ios::left) << setw(10) << it.number
				<< setw(15) << it.name
				<< setiosflags(ios::right) << setw(10) << it.quantity
				<< setiosflags(ios::fixed)
				<< setprecision(2) << setw(10) << it.price
				<< resetiosflags(ios::right) << endl;
		}
		f.read((char*)&it, sizeof(it));
	}
}

