#include "Game.h"
#include "player.h"


ISubject * CreateSubject()
{
	return new CGame();
}

CGame::CGame()
{
}

CGame::~CGame()
{
}

int CGame::GetGameResult()
{
	return rand()%10;
}

void CGame::Notify()
{
	CPlayer* pTemp = nullptr;
	if (!m_listResult.size())
	{
		m_listResult.resize(m_listObserver.size());
	}

	int nTemp = 0;
	int nGameResult = GetGameResult();
	for (int i = 0; i < m_listObserver.size(); i++)
	{
		pTemp = (CPlayer*)m_listObserver[i];
		pTemp->Update(nGameResult);
		nTemp = pTemp->GetState();
		m_listResult[i] += nTemp;
	}
}
