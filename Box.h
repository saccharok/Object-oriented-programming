#include <iostream>
#include <string.h>
#include <list>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class IBox
{
public:	
	IBox() {}
	virtual void about() = 0;
};

class Product : public IBox
{
protected:
	string prod;
public:
	Product(string _prod)
	{
		this->prod = _prod;
	}
	virtual void about()
	{
		cout << "\n" << this->prod;
	}
};

class Composite : public IBox
{
private:
	list <IBox*> box;
public:
	void addProd(IBox* prod)
	{
		box.push_back(prod);
	}
	void delProd(IBox* prod)
	{
		box.remove(prod);
		prod->about();
		cout << " delete from box";
	}
	virtual void about()
	{
		cout << "\nThe box with products changes the filling";
	}
};