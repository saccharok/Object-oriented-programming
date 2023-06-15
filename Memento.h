#pragma once
#include <iostream>
#include <vector>
#include "State.h"
using namespace std;

class Memento	//интерфейс снимка
{
public:
	virtual OrderInfo * GetState() = 0;
	virtual void coutState() = 0;
};

class CertainMemento : public Memento //реализация интерфейса - конкретный снимок состояния
{
	OrderInfo* currentOrder;
public:
	
	CertainMemento(OrderInfo* order)
	{
		this->currentOrder = order;
	}
	
	virtual OrderInfo* GetState()
	{
		return currentOrder;
	}
	
	virtual void coutState()
	{
		currentOrder->coutState();
	}
};

class Creator	//создатель снимков
{
	OrderInfo* order;
public:
	Creator(OrderInfo* order)
	{
		cout << "Initial state: ";
		this->order = order;
		this->order->coutState();
	}
	
	Memento* saveState()	//сохранение состояния
	{
		return new CertainMemento(order);
	}
	
	void Restore(Memento* mem)
	{
		order = mem->GetState();
		cout << "Current state: ";
		order->coutState();
	}
	
	void Do()
	{
		cout << "It's working!" << endl;
	}
};

class Keeper	//смотритель
{
	vector<Memento*> memes;	//список состояний
	Creator* creator;
public:
	Keeper(Creator* creator) 
	{
		this->creator = creator;
	}
	
	~Keeper()
	{
		for (auto m : memes)
			delete m;
	}
	
	void saveInCreator()
	{
		cout << "Save state in creator" << endl;
		memes.push_back(creator->saveState());
	}

	void Restoring()
	{
		if (!memes.size())
			return;
		Memento* mem = memes.back();
		memes.pop_back();
		cout << "Restoring state in creator"; 
		mem->coutState();
		creator->Restore(mem);
	}

	void showHistory()
	{
		cout << endl << "History: " << endl;
		for (int i = 0; i < memes.size(); i++)
		{
			Memento* mem = memes[i];
			mem->coutState();
		}
	}
};