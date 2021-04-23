
/*@file
*************************************************************************
模块:  PBDWE[version].dll
文件:  MemoryManager.h
功能:  CMemoryManager 内存池管理模块
作者:  laihao 2018-06-25;
************************************************************************/

#pragma once
#include <Windows.h>

namespace DebugerNS
{
	/*@class
		*******************************************************************
		类名:  CMemoryManager
		功能:  内存池管理类
		备注:  
		作者:  laihao 2018-06-25;
	**********************************************************************/
	class CMemoryManager
	{
	public:
		static CMemoryManager* GetInstance();			//获取单件实例

		void* Alloc(ULONG ulSize);						//分配内存
		void* ReAlloc(void* pOld, ULONG ulSize);		//重新分配内存
		LPTSTR AllocStr(ULONG ulSize);					//分配内存字符串
		LPTSTR ReAllocStr(LPTSTR pOld, ULONG ulSize);	//分配内存字符串
		void Free(void* pMem);							//释放内存

	protected:
		CMemoryManager(void);
		~CMemoryManager(void);

	protected:
		HANDLE m_hHeap;
		static CMemoryManager s_Instance;
	};
}
