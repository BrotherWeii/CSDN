#pragma once
#include "ILock.h"
#include <Windows.h>
#include <string>
using std::wstring;


namespace DownLoader{

	/*@class
	*******************************************************************
	模块:  Thread
	文件:  Mutux.h
	功能:  同步对象 互斥量
	作者:  Aijiawei 2021/04/22
	*******************************************************************/
	class CMutux : public ILock
	{
	public:
		CMutux();
		~CMutux();

	public:
		virtual bool Lock();
		virtual bool Unlock();

		bool Create(LPCTSTR lpMutuxName, BOOL bInitOwener); 
		void Destroy();

		LPCWSTR GetMutuxName();
		HANDLE GetMutuxHandle();

	private:
		HANDLE   m_hMutux;
		wstring  m_strMutuxName;
	};
}