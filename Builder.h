#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Order
{
public:
	bool paymentCheck;
	Order(bool check)
	{
		paymentCheck = check;
	}
};

class Builder
{
public:
	virtual void reset(Order*) = 0;
	virtual void productSelection() = 0;
	virtual void orderFormation() = 0;
	virtual void costWithdrawal() = 0;
	virtual void paymentMethod() = 0;
};

class OrderBuilder : public Builder
{
private:
	Order* order;
public:
	virtual void reset(Order* ord)
	{
		order = ord;
	}
	virtual void productSelection()
	{
		cout << "Products are added to the cart" << endl;
	}
	virtual void orderFormation()
	{
		cout << "An order is formed from the products in the basket" << endl;
	}
	virtual void costWithdrawal()
	{
		cout << "You have to pay some money" << endl;
	}
	virtual void paymentMethod()
	{
		if (order->paymentCheck == true)
		{
			cout << "Pay for the order now, otherwise the assembly will not start" << endl;
		}
		else
		{
			cout << "OK. You can pay later" << endl;
		}
	}
};

class Director
{
public:
	void constructOrder(Order* ord)
	{
		Builder* build = new OrderBuilder();
		build->reset(ord);
		build->productSelection();
		build->orderFormation();
		build->costWithdrawal();
		build->paymentMethod();
	}
};