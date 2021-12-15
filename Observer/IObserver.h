#pragma once

//观察者
class IObserver
{
public:
	virtual void Update() = 0;  //更新
};

IObserver* CreateObserver(const char*);
