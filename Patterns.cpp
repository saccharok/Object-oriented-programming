// Patterns - Земская ПИ-02

//lab2
#include "Worker.h"
#include "Order.h"
//
#include <iostream>
using namespace std;

int main()
{
    cout << "1 - Delegation" << endl;
    cout << "2 - Proxy" << endl;
    int type = 0;
    cin >> type;
    switch (type)
    {
		case(1):
		{
			cout << "Warehousez manager:" << endl;
			WarehousezManager wm1;
			wm1.receiptGoods();
			wm1.processingGoods();
			wm1.broadcastGoods();
			cout << endl << "Loader:" << endl;
			Loader l1;
			l1.receiptGoods();
			l1.processingGoods();
			l1.broadcastGoods();
			cout << endl << "Driver:" << endl;
			Driver d1;
			d1.receiptGoods();
			d1.processingGoods();
			d1.broadcastGoods();
			cout << endl << "Sorter:" << endl;
			Sorter s1;
			s1.receiptGoods();
			s1.processingGoods();
			s1.broadcastGoods();
			cout << endl << "Pick-up point specialist:" << endl;
			PickUpPointSpecialist pups1;
			pups1.receiptGoods();
			pups1.processingGoods();
			pups1.broadcastGoods();
			cout << endl << "Courier:" << endl;
			Courier c1;
			c1.receiptGoods();
			c1.processingGoods();
			c1.broadcastGoods();
			break;
		}

		case(2):
		{
			cout << "Order - 102030, 89996541965, 127245614" << endl << endl
				<< "Usual:" << endl;
			cout << "1 - 102030" << endl << "2 - 89996541965" << endl << "3 - 100030" << endl;
			IOrder* o1 = new OrderForBuyer(102030, 89996541965, 127245614);
			cout << "1:" << endl;
			o1->getGoods(102030);
			cout << "2:" << endl;
			o1->getGoods(89996541965);
			cout << "3:" << endl;
			o1->getGoods(100030);
			cout << endl << "Proxy:" << endl;
			cout << "1 - 102030" << endl << "2 - 89996541965" << endl << "3 - 100030" << endl;
			IOrder* po1 = new ProxyOrder(102030, 89996541965, 127245614);
			cout << "1:" << endl;
			po1->getGoods(102030);
			cout << "2:" << endl;
			po1->getGoods(89996541965);
			cout << "3:" << endl;
			po1->getGoods(100030);
			break;
		}
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
