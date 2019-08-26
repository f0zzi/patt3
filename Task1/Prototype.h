#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Weapon
{
private:
	int power = 0;
	int bullets = 0;
	int spentBullets = 0;
public:
	Weapon(int power, int bullets, int spentBullets) :power(power), bullets(bullets), spentBullets(spentBullets) {}
	virtual void Fire() = 0;
	virtual Weapon* Clone() = 0;
	virtual void Reload() = 0;
	int GetPower() const { return power; }
	int GetBullets() const { return bullets; }
	int GetSpentBullets() const { return spentBullets; }
	void SetPower(int power)
	{
		if (power > 0)
			this->power = power;
	}
	void SetBullets(int bullets)
	{
		if (bullets >= 0)
			this->bullets = bullets;
	}
	void SetSpentBullets(int spentBullets)
	{
		if (spentBullets > 0)
			this->spentBullets = spentBullets;
	}
	virtual void Info()
	{
		string className = typeid(*this).name();
		cout << setw(10) << className.substr(6, className.size() - 6) << "\t" 
			 << "Power: " << GetPower() << "\t" << "Bullets: " << GetBullets() << "\t" 
			 << "Shooting rate: " << GetSpentBullets() << endl;
	}
};

class Gun : public Weapon
{
private:
	static const int MAX_BULLETS = 10;
public:
	Gun() :Weapon(5, MAX_BULLETS, 1) {}
	void Fire()
	{
		if (GetBullets())
		{
			cout << "Bang!" << endl;
			SetBullets(GetBullets() - 1);
		}
		else
			cout << "Need reload" << endl;
	}
	void Reload()
	{
		if (GetBullets() == MAX_BULLETS)
			cout << "No need to reload." << endl;
		else
		{
			cout << "Reloading." << endl;
			SetBullets(MAX_BULLETS);
		}
	}
	Weapon* Clone()
	{
		return new Gun(*this);
	}
};

class Machinegun : public Weapon
{
private:
	static const int MAX_BULLETS = 100;
public:
	Machinegun() :Weapon(10, MAX_BULLETS, 15) {}
	void Fire()
	{
		if (GetBullets() > 0)
		{
			for (int i = 0; i < GetSpentBullets() && GetBullets() > 0; i++)
			{
				cout << "Bang!" << "  ";
				SetBullets(GetBullets() - 1);
			}
			cout << endl;
		}
		else
			cout << "Need reload" << endl;
	}
	void Reload()
	{
		if (GetBullets() == MAX_BULLETS)
			cout << "No need to reload." << endl;
		else
		{
			cout << "Reloading." << endl;
			SetBullets(MAX_BULLETS);
		}
	}
	Weapon* Clone()
	{
		return new Machinegun(*this);
	}
};

class WeaponStock
{
private:
	vector<Weapon*>stock;
public:
	void AddWeapon(Weapon* weapon)
	{
		stock.push_back(weapon);
	}
	Weapon* GetWeapon(size_t id)
	{
		if (id < stock.size() && id > 0)
			return stock[id]->Clone();
		return stock[0]->Clone();
	}
	void ShowWeapons()
	{
		if (!stock.size())
			cout << "Stock is empty." << endl;
		else
		{
			for (size_t i = 0; i < stock.size(); i++)
			{
				cout << "ID: " << i + 1 << "\t";
				stock[i]->Info();
			}
		}
	}
	int StockSize() const { return stock.size(); }
};