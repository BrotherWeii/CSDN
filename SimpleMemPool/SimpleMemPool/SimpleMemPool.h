/*@file
*************************************************************************
ģ��:  PBDebuger[version].DLL&Host64x&HostPBD
�ļ�:  SimpleMemPool.cpp
����:  CSimpleMemPool �����ڴ��
����:  Aijiawei 2020-12-10;
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
	HANDLE m_Heap;			//�Ѿ��
	LPVOID m_pMem;			//�ڴ��׵�ַ
	UINT  m_nMemCapacity;	//�ڴ�����
	UINT  m_nMemUsedSize;	//�ڴ����ô�С
};