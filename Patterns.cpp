// Patterns - Земская ПИ-02
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#include "Builder.h"

int main()
{
	cout << "Builder" << endl;
	Director* dir = new Director();
	cout << endl << "Order 1 - payment check is true" << endl;
	Order* o1 = new Order(true);
	dir->constructOrder(o1);
	cout << endl << "Order 2 - payment check is false" << endl;
	Order* o2 = new Order(false);
	dir->constructOrder(o2);
}
