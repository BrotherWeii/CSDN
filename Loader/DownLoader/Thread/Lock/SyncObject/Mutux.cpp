#pragma once
#include "Mutux.h"

//Remark
/*
CreateMutex()         //创建互斥对象，并获得所有权
ReleaseMutex()        //释放互斥对象所有权
CloseHandle()         //销毁互斥对象
WaitForSingleObject() //等待函数，请求互斥量的所有权
OpenMutux()           //其他进程的线程可以通过名称获取该互斥对象的句柄
*/

namespace DownLoader{

	CMutux::CMutux()
		:m_hMutux(NULL)
		,m_strMutuxName(L"")
	{

	}

	CMutux::~CMutux()
	{
		Destroy();
	}

	bool CMutux::Lock()
	{
		if (!m_hMutux)
			return false;

		return (WAIT_OBJECT_0 == ::WaitForSingleObject(m_hMutux,INFINITE));
	}

	bool CMutux::Unlock()
	{
		if (!m_hMutux)
			return false;

		return (TRUE ==::ReleaseMutex(m_hMutux));
	}

	void CMutux::Destroy()
	{
		if (m_hMutux)
		{
			::CloseHandle(m_hMutux);
			m_hMutux = NULL;
		}
	}

	bool CMutux::Create( LPCTSTR lpMutuxName, BOOL bInitOwener )
	{
		if (m_hMutux)
			Destroy();

		HANDLE hMutux = ::CreateMutex(NULL, bInitOwener, lpMutuxName);
		if (!hMutux)
			return false;

		m_hMutux = hMutux;
		(nullptr == lpMutuxName) ? m_strMutuxName = L"" : m_strMutuxName = lpMutuxName;

		return true;
	}

	LPCWSTR CMutux::GetMutuxName()
	{
		return m_strMutuxName.empty() ? NULL : m_strMutuxName.c_str();
	}

	HANDLE CMutux::GetMutuxHandle()
	{
		return m_hMutux;
	}

}