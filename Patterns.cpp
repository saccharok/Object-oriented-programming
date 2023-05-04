// Patterns - Земская ПИ-02

//lab5-6
#include "IDocs.h"
#include "Pack.h"
#include "Box.h"

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	cout << "3 - Adapter" << endl;
	cout << "4 - Decorator" << endl;
	cout << "5 - Composite" << endl;
	//cout << "6 - Iterator" << endl;
    int type = 0;
    cin >> type;
    switch (type)
    {
		case(3):
		{
			cout << "Order#1 - 102030" << endl;
			OriginDoc* od = new OriginDoc();
			string n = "102030";
			n = od->readDoc(n);
			cout << "Order#2 - 102031" << endl;
			n = "102031";
			IDocs* conv = new Adapter();
			conv->getDoc(n);
			break;
		}

		case(4):
		{
			Packing pack;
			cout << pack.getInfo() << "Cost: " << pack.getCost();
			Delicate del(&pack);
			cout << del.getInfo() << "Cost: " << del.getCost();
			NotWet nw(&del);
			NotFlip nf(&nw);
			NotOpen no(&nf);
			NotUseHook nuh(&no);
			cout << nuh.getInfo() << "Cost: " << nuh.getCost();
			break;
		}

		case(5):
		{
			Composite box;
			box.about();
			IBox* knife = new Product("knife");
			knife->about();
			box.addProd(knife);
			IBox* fork = new Product("fork");
			fork->about();
			box.addProd(fork);
			box.delProd(knife);
			break;
		}
    }
}