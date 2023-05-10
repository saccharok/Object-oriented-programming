#pragma once
#include <iostream>
using namespace std;

//����������
class Sorting
{
public:
	virtual void getInfo() = 0;
};

class StorageSorting : public Sorting
{
public:
	void getInfo() override
	{
		cout << "Sorting in the storage" << endl;
	}
};

class Sorting�enterSorting : public Sorting
{
public:
	void getInfo() override
	{
		cout << "Sorting in the sorting center" << endl;
	}
};

class PickupSorting : public Sorting
{
public:
	void getInfo() override
	{
		cout << "Sorting in the pickup point" << endl;
	}
};

//����������
class Preparing
{
public:
	virtual void getInfo() = 0;
};

class StoragePreparing : public Preparing
{
public:
	void getInfo() override
	{
		cout << "Preparing in the storage" << endl;
	}
};

class Sorting�enterPreparing : public Preparing
{
public:
	void getInfo() override
	{
		cout << "Preparing in the sorting center" << endl;
	}
};

class PickupPreparing : public Preparing
{
public:
	void getInfo() override
	{
		cout << "Preparing in the pickup point" << endl;
	}
};

//��������
class Shipment
{
public:
	virtual void getInfo() = 0;
};

class StorageShipment : public Shipment
{
public:
	void getInfo() override
	{
		cout << "Shipment in the storage" << endl;
	}
};

class Sorting�enterShipment : public Shipment
{
public:
	void getInfo() override
	{
		cout << "Shipment in the sorting center" << endl;
	}
};

class PickupShipment : public Shipment
{
public:
	void getInfo() override
	{
		cout << "Shipment in the pickup point" << endl;
	}
};

//�������
class Factory
{
public:
	virtual Sorting* getSorting() = 0;
	virtual Preparing* getPreparing() = 0;
	virtual Shipment* getShipment() = 0;
};

//�����
class Storage : public Factory
{
public:
	Sorting* getSorting()
	{
		return new StorageSorting();
	}
	Preparing* getPreparing()
	{
		return new StoragePreparing();
	}
	Shipment* getShipment()
	{
		return new StorageShipment();
	}
};

//������������� �����
class SortingCenter : public Factory
{
public:
	Sorting* getSorting()
	{
		return new Sorting�enterSorting();
	}
	Preparing* getPreparing()
	{
		return new Sorting�enterPreparing();
	}
	Shipment* getShipment()
	{
		return new Sorting�enterShipment();
	}
};

class PickupPoint : public Factory
{
public:
	Sorting* getSorting()
	{
		return new PickupSorting();
	}
	Preparing* getPreparing()
	{
		return new PickupPreparing();
	}
	Shipment* getShipment()
	{
		return new PickupShipment();
	}
};

class Show
{
private:
	Sorting* sorting;
	Preparing* preaparing;
	Shipment* shipment;
public:
	Show(Factory* factory)
	{
		sorting = factory->getSorting();
		sorting->getInfo();
		preaparing = factory->getPreparing();
		preaparing->getInfo();
		shipment = factory->getShipment();
		shipment->getInfo();
	}
};