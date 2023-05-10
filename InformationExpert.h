#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#define MAX 100

using namespace std;

class Prod
{
private:
	int price;
public:
	virtual int cost(string _name)
	{
		if (_name == "Lemonade")
			this->price = 50;
		if (_name == "Coffee")
			this->price = 100;
		if (_name == "Sweets")
			this->price = 65;
		return this->price;
	}
};

class ProdsPrice
{
private:
	Prod* prod;
	int count;
public:
	virtual int totalCost(string name, int _count)
	{
		this->count = _count;
		cout << (count * prod->cost(name));
		return (count * prod->cost(name));
	}
};

class OrderCost
{
private:
	ProdsPrice order;
public:
	virtual int getCost(int prodsCount, string name[], int count[])
	{
		int orderCost = 0;
		for (int i = 0; i < prodsCount; i++)
		{
			cout << endl << name[i] << " * " << count[i] << " = ";
			orderCost += order.totalCost(name[i], count[i]);
		}
		return orderCost;
	}
};