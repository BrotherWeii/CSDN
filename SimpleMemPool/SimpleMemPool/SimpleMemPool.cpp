#include "SimpleMemPool.h"

#define DEFAULT_MEMORY_POOL_SIZE (1024*512)  //Ĭ���ȷ���0.5M
#define DEFAULT_RESIZE_NUM       (2)		 //Ĭ�����ݱ���
#define DEFAULT_BLOCK_BASE_NUM   (1024)      //Ĭ�ϻ���

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
	//��1024Ϊ����ʹ��
	unSize = DEFAULT_BLOCK_BASE_NUM * (unSize / DEFAULT_BLOCK_BASE_NUM + 1);

	//��������̶���С
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
		//ȷ�����������Ƿ��㹻
		if (unSize > m_nMemCapacity)
		{
			//������,��2������,
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
			//����ʣ���ڴ��С�Ƿ���
			UINT unLastMem = m_nMemCapacity - m_nMemUsedSize;
			if (unLastMem > unSize)
			{
				UINT unCurrent = m_nMemUsedSize;
				m_nMemUsedSize += unSize;
				return (byte*)m_pMem + unCurrent;
			}
			else
			{
				//�����ڴ�
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


