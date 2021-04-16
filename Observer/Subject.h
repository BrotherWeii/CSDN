#pragma once
#include "ISubject.h"
#include <vector>


//目标
class CSubject : public ISubject
{
public:
	CSubject();
	~CSubject();

public:
	void Attach(IObserver* pObserver);		//添加观察者
	void Dettach(IObserver* pObserver);		//删减观察者
	void Notify();							//通知观察者

public:
	std::vector<IObserver*> m_listObserver;	//观察者们
};
