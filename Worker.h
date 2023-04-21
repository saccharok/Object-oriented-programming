#ifndef __WORKER
#define __WORKER
#include "Actions.h"
#include "Behavior.h"
using namespace std;

class Worker	//����������� ����� ����������� 
{
public:
	IReceipt* receipt;
	IProcessing* processing;
	IBroadcast* broadcast;
	Worker() {}
	//������������� ��������
	void receiptGoods() { receipt->receipt(); }
	void processingGoods() { processing->processing(); }
	void broadcastGoods() { broadcast->broadcast(); }
};

//���������� ������
class WarehousezManager :public Worker
{
public:
	WarehousezManager()
	{
		receipt = new receiptWarehousezManager();
		processing = new processingWarehousezManager();
		broadcast = new broadcastWarehousezManager();
	}
};

//�������
class Loader :public Worker
{
public:
	Loader()
	{
		receipt = new receiptLoader();
		processing = new processingLoader();
		broadcast = new broadcastLoader();
	}
};

//��������
class Driver :public Worker
{
public:
	Driver()
	{
		receipt = new receiptDriver();
		processing = new processingDriver();
		broadcast = new broadcastDriver();
	}
};

//�����������
class Sorter :public Worker
{
public:
	Sorter()
	{
		receipt = new receiptSorter;
		processing = new processingSorter();
		broadcast = new broadcastSorter();
	}
};

//���������� ���
class PickUpPointSpecialist : public Worker
{
public:
	PickUpPointSpecialist()
	{
		receipt = new receiptPickUpPointSpecialist();
		processing = new processingPickUpPointSpecialist();
		broadcast = new broadcastPickUpPointSpecialist();
	}
};

//������
class Courier : public Worker
{
public:
	Courier()
	{
		receipt = new receiptCourier;
		processing = new processingCourier();
		broadcast = new broadcastCourier();
	}
};

#endif __WORKER