#pragma once
#include <iostream>
using namespace std;

class Transport
{
public:
	~Transport() {};
	virtual void createCourier() = 0;
};

class Car : public Transport
{
public:
	void createCourier() override
	{
		cout << "Courier on car" << endl;
	}
};

class Bicycle : public Transport
{
public:
	void createCourier() override
	{
		cout << "Courier on bicycle" << endl;
	}
};

class Feet : public Transport
{
public:
	void createCourier() override
	{
		cout << "Courier on his feet" << endl;
	}
};

class DeliveryType
{
private:
	Transport* transfer;
public:
	~DeliveryType() {};
	virtual Transport* createTransfer() = 0;
	virtual Transport* operation()
	{
		transfer = this->createTransfer();
		transfer->createCourier();
		return transfer;
	}
};

class Express : public DeliveryType
{
public:
	Express() : DeliveryType() {};
	virtual Transport* createTransfer()
	{
		cout << "Express delivery type" << endl;
		return new Car();
	}
};

class Standard : public DeliveryType
{
public:
	Standard() : DeliveryType() {};
	virtual Transport* createTransfer()
	{
		cout << "Standard delivery type" << endl;
		return new Bicycle();
	}
};

class Cheap : public DeliveryType
{
public:
	Cheap() : DeliveryType() {};
	virtual Transport* createTransfer()
	{
		cout << "Cheap delivery type" << endl;
		return new Feet();
	}
};