// Patterns - Земская ПИ-02
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
#include "FactoryMethod.h"
#include "AbstractFactory.h"
int main()
{
	cout << "9 - Factory method" << endl;
	cout << "10 - Abstract factory" << endl;
    int type = 0;
    cin >> type;
    switch (type)
    {
		case(9):
		{
			DeliveryType* del1 = new Express();
			Transport* t1 = del1->operation();
			cout << endl;
			DeliveryType* del2 = new Standard();
			Transport* t2 = del2->operation();
			cout << endl;
			DeliveryType* del3 = new Cheap();
			Transport* t3 = del3->operation();
			cout << endl;
			break;
		}

		case(10):
		{
			cout << endl << "Order route:" << endl;
			Factory* f1 = new Storage();
			Show* s1 = new Show(f1);
			Factory* f2 = new SortingCenter();
			Show* s2 = new Show(f2);
			Factory* f3 = new PickupPoint();
			Show* s3 = new Show(f3);
			break;
		}
    }
}