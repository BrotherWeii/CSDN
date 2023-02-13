#include "SimpleMemPool.h"

#define DEFAULT_MEMORY_POOL_SIZE (1024*512)  //默认先分配0.5M
#define DEFAULT_RESIZE_NUM       (2)		 //默认扩容倍数
#define DEFAULT_BLOCK_BASE_NUM   (1024)      //默认基数

CSimpleMemPool* CSimpleMemPool::m_pInstance = NULL;

CSimpleMemPool::CSimpleMemPool()
	: m_Heap(NULL)
	, m_pMem(NULL)
	, m_nMemCapacity(0)
	, m_nMemUsedSize(0)
{
	m_Heap = ::HeapCreate(NULL, 0, 0);
}

CSimpleMemPool::~CSimpleMemPool()
{
	::HeapDestroy(m_Heap);
}

CSimpleMemPool * CSimpleMemPool::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new CSimpleMemPool();

	return m_pInstance;
}

void CSimpleMemPool::Release()
{
	Free();

	delete this;
}

LPVOID CSimpleMemPool::Alloc(UINT unSize)
{
	//以1024为基数使用
	unSize = DEFAULT_BLOCK_BASE_NUM * (unSize / DEFAULT_BLOCK_BASE_NUM + 1);

	//最初创建固定大小
	if (!m_pMem)
	{
		m_pMem = ::HeapAlloc(m_Heap, HEAP_ZERO_MEMORY, unSize>DEFAULT_MEMORY_POOL_SIZE?unSize:DEFAULT_MEMORY_POOL_SIZE);
		if (!m_pMem)
			return NULL;

		m_nMemCapacity = unSize > DEFAULT_MEMORY_POOL_SIZE ? unSize : DEFAULT_MEMORY_POOL_SIZE;
		m_nMemUsedSize += unSize;
		return m_pMem;
	}
	else
	{
		//确定现有容量是否足够
		if (unSize > m_nMemCapacity)
		{
			//需扩容,以2倍扩容,
			UINT unMemSize = m_nMemCapacity;
			while (unSize > unMemSize)
			{
				unMemSize *= DEFAULT_RESIZE_NUM;
			}

			LPVOID pMem = NULL;
			pMem = ::HeapReAlloc(m_Heap, HEAP_ZERO_MEMORY, m_pMem, unMemSize);
			if (!pMem)
				return NULL;
			memset(pMem, 0, unSize);

			m_pMem = pMem;
			m_nMemCapacity = unMemSize;
			m_nMemUsedSize += unSize;
			return m_pMem;
		}
		else
		{
			//计算剩余内存大小是否够用
			UINT unLastMem = m_nMemCapacity - m_nMemUsedSize;
			if (unLastMem > unSize)
			{
				UINT unCurrent = m_nMemUsedSize;
				m_nMemUsedSize += unSize;
				return (byte*)m_pMem + unCurrent;
			}
			else
			{
				//重设内存
				memset(m_pMem, 0, m_nMemCapacity);
				m_nMemUsedSize = 0;

				m_nMemUsedSize += unSize;
				return m_pMem;
			}
		}	
	}
	
}

void CSimpleMemPool::Free()
{
	if (m_pMem)
		::HeapFree(m_Heap, 0, m_pMem);

	m_pMem = NULL;
	m_nMemCapacity = 0;
	m_nMemUsedSize = 0;
}


