#include "Player.h"
#include <iostream>

enum enumState
{
	eFail = -1,
	eNotJoin,
	eSuccess
};

IObserver * CreateObserver(const char* pstrName)
{
	return new CPlayer(pstrName);
}

CPlayer::CPlayer()
{
	m_strPlayerName = "";
	m_nGusNum = 0;
	m_IsJoin = false;
	m_nState = 0;
}

CPlayer::CPlayer(const char * pstrName)
	:CPlayer()
{
	m_strPlayerName = pstrName;
}

CPlayer::~CPlayer()
{

}

void CPlayer::Update(int nGameResult)
{
	const char* pstrResult = nullptr;

	if (m_IsJoin)
	{
		bool bIsGusRight = (nGameResult == m_nGusNum);
		if (bIsGusRight)
		{
			SetState(eSuccess);
			pstrResult = "猜中了";
		}
		else
		{
			SetState(eFail);
			pstrResult = "没猜中";
		}
	}
	else
	{
		SetState(eNotJoin);
		pstrResult = "没参与";
	}

	std::cout << m_strPlayerName.c_str() << pstrResult << std::endl;
	
	m_IsJoin = false;
}

void CPlayer::SetGusNum(int nGusNum)
{
	m_IsJoin = true;
	m_nGusNum = nGusNum;
}

void CPlayer::SetState(int nState)
{
	m_nState = nState;
}

int CPlayer::GetState()
{
	return m_nState;
}