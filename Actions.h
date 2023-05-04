#ifndef __ACTIONS
#define __ACTIONS

//интерфейсы действий сотрудников
class IReceipt	//получение товара
{
public:
	virtual void receipt() = 0;
};
class IProcessing	//работа с товаром
{
public:
	virtual void processing() = 0;
};
class IBroadcast	//передача товара
{
public:
	virtual void broadcast() = 0;
};

#endif