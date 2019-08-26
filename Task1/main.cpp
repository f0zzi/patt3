#include <iostream>
#include <Windows.h>
#include "Prototype.h"
using namespace std;

int main()
{
	WeaponStock stock;
	stock.AddWeapon(new Gun());
	Machinegun m60;
	stock.AddWeapon(&m60);
	stock.AddWeapon(stock.GetWeapon(1));
	Weapon* gun;

	int choice;
	do
	{
		system("cls");
		stock.ShowWeapons();
		cout << "Choose weapon: ";
		cin >> choice;
		if (choice < 1 || choice > stock.StockSize())
		{
			cout << "Invalid input." << endl;
			system("pause");
		}
		else
			break;
	} while (true);

	gun = stock.GetWeapon(choice - 1);
	while (choice != 0)
	{
		system("cls");
		gun->Info();
		cout << "(1) Fire\t (2) Reload\t (0) Exit" << endl;
		cout << "Choose option: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			gun->Fire();
			break;
		case 2:
			gun->Reload();
			break;
		case 0:
			cout << "Have a nice day." << endl;
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
		system("pause");
	}
	return 0;
}