/*@file
*************************************************************************
模块:  PBDWE[version].dll
文件:  MemoryManager.cpp
功能:  CMemoryManager 内存池管理模块
作者:  laihao 2018-06-25;
************************************************************************/
#include "MemoryManager.h"

namespace DebugerNS
{
	CMemoryManager CMemoryManager::s_Instance;

	CMemoryManager::CMemoryManager(void)
		: m_hHeap(NULL)
	{
		m_hHeap = HeapCreate(NULL, 0, 0);
	}

	CMemoryManager::~CMemoryManager(void)
	{
		HeapDestroy(m_hHeap);
	}


	/*@function
	*******************************************************************
	功  能:  分配内存
	参  数:  lSize 内存大小
	返回值:  新内存地址
	------------------------------------------------------------------
	作  者:  laihao 2018-06-25;
	******************************************************************/
	void * CMemoryManager::Alloc(ULONG ulSize)
	{
		return HeapAlloc(m_hHeap, HEAP_ZERO_MEMORY, (SIZE_T)ulSize);
	}

	void * CMemoryManager::ReAlloc(void *pOld, ULONG ulSize)
	{
		return HeapReAlloc(m_hHeap, HEAP_ZERO_MEMORY, pOld, (SIZE_T)ulSize);
	}

	/*@function
	*******************************************************************
	功  能:  分配内存字符串
	参  数:  lSize 字符串长度
	返回值:  新内存地址
	------------------------------------------------------------------
	作  者:  laihao 2018-06-25;
	******************************************************************/
	LPTSTR CMemoryManager::AllocStr(ULONG ulSize)
	{
		return (LPTSTR)Alloc(ulSize * sizeof(TCHAR));
	}

	LPTSTR CMemoryManager::ReAllocStr(LPTSTR pOld, ULONG ulSize)
	{
		return (LPTSTR)ReAlloc((void*)pOld, ulSize * sizeof(TCHAR));
	}

	/*@function
	*******************************************************************
	功  能:  释放内存
	参  数:  pMem 内存地址
	返回值:  
	------------------------------------------------------------------
	作  者:  laihao 2018-06-25;
	******************************************************************/
	void CMemoryManager::Free(void *pMem)
	{
		HeapFree(m_hHeap, NULL, pMem);
	}

	CMemoryManager* CMemoryManager::GetInstance()
	{
		return &s_Instance;
	}
}
