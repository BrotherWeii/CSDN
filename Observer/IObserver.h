#pragma once

//�۲���
class IObserver
{
public:
	virtual void Update() = 0;  //����
};

IObserver* CreateObserver(const char*);
