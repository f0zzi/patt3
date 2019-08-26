#include <iostream>
#include "Adapter.h"
using namespace std;

int main()
{
	CarConsole* car = new Adaptedcar();
	Driver d;
	d.SetVehicle(car);
	d.TestDrive();
	system("pause");
	return 0;
}