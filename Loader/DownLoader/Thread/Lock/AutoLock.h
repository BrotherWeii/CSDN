#pragma once
#include "SyncObject/Mutux.h"



namespace DownLoader{

    /*@class
    *******************************************************************
    模块:  Thread
    文件:  AutoLock.h
    功能:  自动锁
    作者:  Aijiawei 2021/04/23
    *******************************************************************/
	class CAutoLock
	{
	public:
		CAutoLock(ILock*pLock);
		~CAutoLock();

	private:
		ILock* m_pLock;
	};
}

