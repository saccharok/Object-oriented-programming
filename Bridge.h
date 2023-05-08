#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class IDelivery
{
protected:
	string kind;
	string type;
public:
	IDelivery() {};
	~IDelivery() {};
	virtual void setType() = 0;
	virtual void getType(string _type) = 0;
	virtual void setKind() = 0;
	virtual void getKind(string _kind) = 0;
	virtual void showType() = 0;
	virtual void showKind() = 0;
};

class Purchase : public IDelivery
{
public:
	virtual void setType()
	{
		this->type = "Standart delivery";
	}
	virtual void getType(string _type)
	{
		this->type = _type;
	}
	virtual void setKind()
	{
		this->kind = "Pickup";
	}
	virtual void getKind(string _kind)
	{
		this->kind = _kind;
	}
	virtual void showType()
	{
		cout << this->type << endl;
	}
	virtual void showKind()
	{
		cout << this->kind << endl;
	}
};

class Delivery
{
private:
	IDelivery* idel;
public:
	Delivery(IDelivery* i)
	{
		idel = i;
	}
	~Delivery() {};
	virtual void setSettings ()
	{
		idel->setType();
		idel->setKind();
	}
	virtual void showSettings()
	{
		idel->showType();
		idel->showKind();
	}
	virtual void customizedType(string _type)
	{
		idel->getType(_type);
	}
	virtual void customizedKind(string _kind)
	{
		idel->getKind(_kind);
	}
};