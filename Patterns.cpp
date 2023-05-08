// Patterns - Земская ПИ-02
#define _CRT_SECURE_NO_WARNINGS
//lab5-6
#include "Bridge.h"
#include "InformationExpert.h"
#include "Facade.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	cout << "6 - Bridge" << endl;
	cout << "7 - Information Expert" << endl;
	cout << "8 - Facade" << endl;
    int type = 0;
    cin >> type;
    switch (type)
    {
		case(6):
		{
			IDelivery* idel = new Purchase();
			Delivery* del = new Delivery(idel);
			del->setSettings();
			del->showSettings();
			cout << endl;
			del->customizedType("Chip delivery");
			del->showSettings();
			cout << endl;
			del->customizedKind("Courier delivery");
			del->showSettings();
			cout << endl;
			break;
		}

		case(7):
		{
			OrderCost* Order = new OrderCost();
			string name[] = { "Lemonade" , "Coffee" , "Sweets" };
			int count[] = { 5, 6, 3 };
			int price = 0;
			price = Order->getCost(3, name, count);
			cout << endl << "Total order price: " << price;
			break;
		}

		case(8):
		{
			Facade* fac = new Facade();
			fac->Goods();
			fac->Transfer();
			break;
		}
    }
}