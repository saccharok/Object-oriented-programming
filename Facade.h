#include "Box.h"
#include "Bridge.h"
#include <iostream>
using namespace std;

class Facade
{
private:
	Composite* box;
	Delivery* del;
public:
	Facade() 
	{
		box = new Composite();
		IDelivery* idel = new Purchase();
		del = new Delivery(idel);
	}
	virtual void Goods()
	{
		Product* prod = new Product("knife");
		box->addProd(prod);
		prod->about();
		prod = new Product("spoon");
		box->addProd(prod);
		prod->about();
		box->about();
		cout << endl;
	}
	virtual void Transfer ()
	{
		del->setSettings();
		del->showSettings();
	}
};