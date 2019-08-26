#pragma once
#include <iostream>
using namespace std;

class Car
{
public:
	void Start()
	{
		cout << "Driving" << endl;
	}
	void Stop()
	{
		cout << "Stoped" << endl;
	}
	void Left(int angle)
	{
		if (angle > 0)
			cout << "Turning " << angle << " degrees left" << endl;
	}
	void Right(int angle)
	{
		if (angle > 0)
			cout << "Turning " << angle << " degrees right" << endl;
	}
};

__interface CarConsole
{
	void Run();
	void Stop();
	void Rotate(int angle);
};

class Adaptedcar : public CarConsole, private Car
{
public:
	void Run()
	{
		Start();
	}
	void Stop()
	{
		Car::Stop();
	}
	void Rotate(int angle)
	{
		if (angle > 0)
			Right(abs(angle));
		else if (angle < 0)
			Left(abs(angle));
	}
};

class Driver
{
private:
	CarConsole* vehicle = nullptr;
public:
	void SetVehicle(CarConsole* vehicle)
	{
		this->vehicle = vehicle;
	}
	void TestDrive()
	{
		if (vehicle != nullptr)
		{
			vehicle->Run();
			vehicle->Rotate(-40);
			vehicle->Rotate(30);
			vehicle->Stop();
		}
		else
			cout << "Give me some vehicle first." << endl;
	}
};