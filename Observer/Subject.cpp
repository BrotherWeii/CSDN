#pragma once
#include "Subject.h"

CSubject::CSubject()
{
}

CSubject::~CSubject()
{
}

void CSubject::Attach(IObserver * pObserver)
{
	if (pObserver)
	{
		m_listObserver.push_back(pObserver);
	}
}

void CSubject::Dettach(IObserver * pObserver)
{
	if (!pObserver)
		return;

	auto it = m_listObserver.begin();
	for (; it != m_listObserver.end(); it++)
	{
		if (*it == pObserver)
		{
			m_listObserver.erase(it);
			break;
		}
	}
}

void CSubject::Notify()
{
	for (auto it : m_listObserver)
	{
		it->Update();
	}
}