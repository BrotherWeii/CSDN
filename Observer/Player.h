#pragma once
#include "Observer.h"
#include <string>

class CPlayer : public CObserver
{
public:
	CPlayer();
	CPlayer(const char* pstrName);
	~CPlayer();

	void Update(int nGameResult);
	void SetGusNum(int nGusNum);

	void SetState(int nState);
	int GetState();

private:
	std::string m_strPlayerName;
	int			m_nGusNum;
	bool		m_IsJoin;
	int			m_nState;
};