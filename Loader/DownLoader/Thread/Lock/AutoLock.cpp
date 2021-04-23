#pragma once
#include "AutoLock.h"

namespace DownLoader{

	CAutoLock::CAutoLock( ILock*pLock )
	{
		if (pLock)
		{
			m_pLock = pLock;
			m_pLock->Lock();
		}
	}

	CAutoLock::~CAutoLock()
	{
		if (m_pLock)
			m_pLock->Unlock();
	}
}
