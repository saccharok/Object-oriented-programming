#ifndef __BEHAVIOUR
#define __BEHAVIOUR
#include "Actions.h"
#include "iostream"
using namespace std;

//специалист склада
class receiptWarehousezManager : public IReceipt
{
public:
	void receipt()
	{
		cout << "Goods received from supplier!" << endl;
	}
};
class processingWarehousezManager : public IProcessing
{
public:
	void processing()
	{
		cout << "Invoice written!" << endl;
	}
};
class broadcastWarehousezManager : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Handed over to the loader!" << endl;
	}
};

//грузчик
class receiptLoader : public IReceipt
{
public:
	void receipt()
	{
		cout << "Goods received from Warehousez Manager!" << endl;
	}
};
class processingLoader : public IProcessing
{
public:
	void processing()
	{
		cout << "Goods are loaded into the machine!" << endl;
	}
};
class broadcastLoader : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Goods delivered with invoice!" << endl;
	}
};

//водитель
class receiptDriver : public IReceipt
{
public:
	void receipt()
	{
		cout << "Invoice received!" << endl;
	}
};
class processingDriver : public IProcessing
{
public:
	void processing()
	{
		cout << "I am driving with goods!" << endl;
	}
};
class broadcastDriver : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Goods delivered with invoice!" << endl;
	}
};

//сортировщик
class receiptSorter : public IReceipt
{
public:
	void receipt()
	{
		cout << "Goods received with invoice!" << endl;
	}
};
class processingSorter : public IProcessing
{
public:
	void processing()
	{
		cout << "I am sorting goods!" << endl;
	}
};
class broadcastSorter : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Goods left in the sorting warehouse!" << endl;
	}
};

//специалист ПВЗ
class receiptPickUpPointSpecialist : public IReceipt
{
public:
	void receipt()
	{
		cout << "Goods received from the driver with an invoice!" << endl;
	}
};
class processingPickUpPointSpecialist : public IProcessing
{
public:
	void processing()
	{
		cout << "I generate documents!" << endl;
	}
};
class broadcastPickUpPointSpecialist : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Hand over the goods to the customer or courier!" << endl;
	}
};

//курьер
class receiptCourier : public IReceipt
{
public:
	void receipt()
	{
		cout << "Goods received with docs from pick-up point specialist!" << endl;
	}
};
class processingCourier : public IProcessing
{
public:
	void processing()
	{
		cout << "I am on my way!" << endl;
	}
};
class broadcastCourier : public IBroadcast
{
public:
	void broadcast()
	{
		cout << "Hand over the goods to the customer!" << endl;
	}
};

#endif 