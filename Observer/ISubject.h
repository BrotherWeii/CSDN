#pragma once
#include "IObserver.h"

//目标（被观察者）
class ISubject
{
public:
	virtual void Attach(IObserver* pObserver) = 0;		//添加观察者
	virtual void Dettach(IObserver* pObserver) = 0;		//删减观察者
	virtual void Notify() = 0;							//通知观察者
};

ISubject* CreateSubject();


