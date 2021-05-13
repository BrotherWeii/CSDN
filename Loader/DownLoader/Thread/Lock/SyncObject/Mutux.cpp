#pragma once
#include "Mutux.h"

/*******************************REMARK***********************************
	CreateMutex()         //创建互斥对象，并获得所有权
	ReleaseMutex()        //释放互斥对象所有权
	CloseHandle()         //销毁对象
	WaitForSingleObject() //等待函数，检查指定的对象当前状态，如果该对象为无信号，则调用线程进入等待状态，直到对象有信号或等待超时为止
	OpenMutux()           //打开互斥对象，其他进程的线程可以通过名称获取该互斥对象的句柄                                                                     
************************************************************************/

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
		// if mutux exists, destroy it and create again
		if (m_hMutux)
			Destroy();

		HANDLE hMutux = ::CreateMutex(NULL, bInitOwener, lpMutuxName);
		if (!hMutux)
			return false;

		// update the mutux info
		m_hMutux = hMutux;
		(NULL == lpMutuxName) ? m_strMutuxName = L"" : m_strMutuxName = lpMutuxName;

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