#ifndef __ACTIONS
#define __ACTIONS

//���������� �������� �����������
class IReceipt	//��������� ������
{
public:
	virtual void receipt() = 0;
};
class IProcessing	//������ � �������
{
public:
	virtual void processing() = 0;
};
class IBroadcast	//�������� ������
{
public:
	virtual void broadcast() = 0;
};

#endif