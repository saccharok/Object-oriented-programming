#include <string.h>
using namespace std;

#ifndef _PACK
#define _PACK

class IPack
{
public:
	virtual int getCost() = 0;
	virtual string getInfo() = 0;
};

#endif

class StickerItem : public IPack
{
protected:
	IPack* item;
public:
	virtual int getCost() = 0;
	virtual string getInfo() = 0;
	StickerItem(IPack* ip) { item = ip; }
	~StickerItem(){}
};

class Packing : public IPack
{
public:
	virtual int getCost()
	{
		return 10;
	}
	virtual string getInfo()
	{
		return string("\nPacking, ");
	}
		
};

class Delicate : public StickerItem
{
public:
	virtual int getCost()
	{
		return 1 + item->getCost();
	}
	virtual string getInfo()
	{
		return item->getInfo() + string("Delicate, ");
	}
	Delicate(IPack *ip):StickerItem(ip){}
};

class NotWet : public StickerItem
{
public:
	virtual int getCost()
	{
		return 2 + item->getCost();
	}
	virtual string getInfo()
	{
		return item->getInfo() + string("Not wet, ");
	}
	NotWet(IPack* ip) :StickerItem(ip) {}
};

class NotFlip : public StickerItem
{
public:
	virtual int getCost()
	{
		return 3 + item->getCost();
	}
	virtual string getInfo()
	{
		return item->getInfo() + string("Not flip, ");
	}
	NotFlip(IPack* ip) :StickerItem(ip) {}
};

class NotOpen : public StickerItem
{
public:
	virtual int getCost()
	{
		return 5 + item->getCost();
	}
	virtual string getInfo()
	{
		return item->getInfo() + string("Not open, ");
	}
	NotOpen(IPack* ip) :StickerItem(ip) {}
};

class NotUseHook : public StickerItem
{
public:
	virtual int getCost()
	{
		return 6 + item->getCost();
	}
	virtual string getInfo()
	{
		return item->getInfo() + string("Not use hook, ");
	}
	NotUseHook(IPack* ip) :StickerItem(ip) {}
};