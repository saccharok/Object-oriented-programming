#include <iostream>
#include <string.h>
using namespace std;

class IDocs
{
public:
	virtual void getDoc(string) = 0;
};

class OriginDoc
{
public:
	string readDoc(string orderNum)
	{
		string file;
		file += orderNum;
		file.push_back('.');
		file.push_back('p');
		file.push_back('d');
		file.push_back('f');
		cout << "Original file is created: " << file << endl;
		return file;
	}
};

class Adapter: public IDocs
{
private:
	OriginDoc* od;
public:
	void getDoc(string orderNum) override
	{
		string file = od->readDoc(orderNum);
		file.erase(file.length() - 3);
		file.push_back('d');
		file.push_back('o');
		file.push_back('c');
		file.push_back('x');
		cout << "Converting: " << file << endl;
	}
	Adapter() { od = new OriginDoc(); }
	~Adapter() { delete od; }
};