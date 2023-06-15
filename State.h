#pragma once
#include <iostream>
using namespace std;

class State
{
public:
	State() {};
	virtual void assembling() = 0;
	virtual void onTheWay() = 0;
	virtual void awaitingIssue() = 0;
	virtual void showState() = 0;
};

class AssemblingState : public State
{
public:
	AssemblingState() {};
	virtual void assembling()
	{
		cout << "Order in assembly" << endl;
	}
	virtual void onTheWay() {};
	virtual void awaitingIssue() {};
	virtual void showState()
	{
		cout << "Order in assembly" << endl;
	}
};

class OnTheWayState : public State
{
public:
	OnTheWayState() {};
	virtual void assembling() {};
	virtual void onTheWay()
	{
		cout << "Order on the way" << endl;
	}
	virtual void awaitingIssue() {};
	virtual void showState()
	{
		cout << "Order on the way" << endl;
	}
};

class AwaitingIssueState : public State
{
public:
	AwaitingIssueState() {};
	virtual void assembling() {};
	virtual void onTheWay() {};
	virtual void awaitingIssue()
	{
		cout << "Order is awaiting issue" << endl;
	}
	virtual void showState()
	{
		cout << "Order is awaiting issue" << endl;
	}
};

class OrderInfo
{
private:
	State* state;
	int check;
public:
	OrderInfo()
	{
		State* s = new AssemblingState();
		state = s;
		state->assembling();
		check = 1;
	}
	State * ReturnState()
	{
		return state;
	}
	void coutState()
	{
		state->showState();
	}
private:
	void stateAssembling()
	{
		State* s = new AssemblingState();
		state = s;
		state->assembling();
		check = 1;
	}
	void stateOnTheWay()
	{
		State* s = new OnTheWayState();
		state = s;
		state->onTheWay();
		check = 2;
	}
	void stateAwaitingIssue()
	{
		State* s = new AwaitingIssueState();
		state = s;
		state->awaitingIssue();
		check = 3;
	}
public:
	void stateUp()
	{
		if (check == 1)
		{
			this->stateOnTheWay();
		}
		else if (check == 2)
		{
			this->stateAwaitingIssue();
		}
		else
		{
			cout << "Get this poor order already" << endl;
		}
	}
	void rejection()
	{
		if (check == 1)
		{
			cout << "You refused the order" << endl;
			this->stateAssembling();
		}
		else if (check == 2)
		{
			cout << "You cannot cancel the order. Wait for the order to appear at the pick-up point" << endl;
		}
		else
		{
			cout << "You refused the order" << endl;
			this->stateAssembling();
		}
	}
};