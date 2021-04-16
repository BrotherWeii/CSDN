#pragma once
#include "Subject.h"

class CGame : public CSubject
{
public:
	CGame();
	~CGame();

public:
	int GetGameResult();
	void Notify();

private:
	std::vector<int> m_listResult;
};