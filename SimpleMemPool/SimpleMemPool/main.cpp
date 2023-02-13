// SimpleMemPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <windows.h>
#include "SimpleMemPool.h"
using namespace std;

void TestLocalTime(const TCHAR* pstr, BOOL bBegin)
{
	TCHAR szBuf[MAX_PATH] = { 0 };
	DWORD dTime = clock();

	bBegin ?
		wsprintfW(szBuf, L"%s:,Begin: %d\r\n", pstr, dTime) :
		wsprintfW(szBuf, L"%s:,End  : %d\r\n", pstr, dTime);

	FILE *pfile = NULL;
	pfile = fopen("C:\\test\\1.txt", "ab");
	if (!pfile)
		return;

	int len = wcslen(szBuf);
	fwrite(szBuf, sizeof(TCHAR), wcslen(szBuf), pfile);
	fclose(pfile);
}

int main()
{
	UINT32 start = clock();
	LPVOID pBuf = NULL;
	byte* pbuf1 = NULL;
	byte* pbuf2 = NULL;
	byte* pbuf3 = NULL;

	for (int i = 0; i < 100000; i++)
	{
		//[Time = ]		
		//pbuf2 = (byte*)CSimpleMemPool::GetInstance()->Alloc(1024 * 1026);
		//memset(pbuf2, 2, 1024 * 1026);

		//[Time = 2109]
		//pBuf = HeapAlloc(heap, HEAP_ZERO_MEMORY, 1024*1024);
		//HeapFree(heap, NULL, pBuf);

		//[Time = 44766]
		//pBuf = new byte[1024 * 1024];
		//delete[]pBuf;

		//[Time = 47406]
		//pBuf = malloc (1024 * 1024);
		//free(pBuf);

		pBuf = NULL;
	}

	//CSimpleMemPool::GetInstance()->Release();
	UINT32 finish = clock();
	cout << "TickCount:" << finish - start << endl;

	system("pause");
}

