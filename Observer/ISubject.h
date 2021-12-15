#pragma once
#include "IObserver.h"

//Ŀ�꣨���۲��ߣ�
class ISubject
{
public:
	virtual void Attach(IObserver* pObserver) = 0;		//��ӹ۲���
	virtual void Dettach(IObserver* pObserver) = 0;		//ɾ���۲���
	virtual void Notify() = 0;							//֪ͨ�۲���
};

ISubject* CreateSubject();


