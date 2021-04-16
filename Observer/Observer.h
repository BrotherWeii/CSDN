#pragma once
#include "IObserver.h"

class CObserver:public IObserver
{
public:
	CObserver();
	~CObserver();

	void Update();
};
