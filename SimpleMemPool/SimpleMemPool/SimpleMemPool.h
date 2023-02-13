/*@file
*************************************************************************
模块:  PBDebuger[version].DLL&Host64x&HostPBD
文件:  SimpleMemPool.cpp
功能:  CSimpleMemPool 简易内存池
作者:  Aijiawei 2020-12-10;
************************************************************************/
#pragma once
#include <windows.h>

class CSimpleMemPool
{
public:
	static CSimpleMemPool* GetInstance();
	void Release();

private:
	CSimpleMemPool();
	~CSimpleMemPool();
	CSimpleMemPool(CSimpleMemPool&) {};
	CSimpleMemPool& operator=(CSimpleMemPool&) {};

public:
	LPVOID Alloc(UINT unSize);
	void Free();

private:
	static CSimpleMemPool* m_pInstance;

private:
	HANDLE m_Heap;			//堆句柄
	LPVOID m_pMem;			//内存首地址
	UINT  m_nMemCapacity;	//内存容量
	UINT  m_nMemUsedSize;	//内存已用大小
};