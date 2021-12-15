// ProcessB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
using namespace std;

#define BUFFER_SIZE 256
#define FILE_MAPPING_NAME L"FILE_MAPPING_NAME"
#define EVENT_NAME1 L"EVNET_NAME1"
#define EVENT_NAME2 L"EVNET_NAME2"

int main()
{
	HANDLE hFile = NULL;
	HANDLE hMap = NULL;
	char szBufIn[BUFFER_SIZE] = { 0 };
	char szBufOut[BUFFER_SIZE] = { 0 };
	LPTSTR pBeginAddress = NULL;

	//打开文件映射
	hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS,FALSE,FILE_MAPPING_NAME);
	if (!hMap)
	{
		cout << "OpenFileMapping Failed!" << endl;
		return 0;
	}

	//获取映射首地址
	pBeginAddress = (LPTSTR)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, BUFFER_SIZE);
	if (!pBeginAddress)
	{
		cout << "MapViewOfFile failed!" << endl;
		return 0;
	}

	HANDLE hEvent1 = OpenEvent(EVENT_ALL_ACCESS, FALSE, EVENT_NAME1);
	HANDLE hEvent2 = OpenEvent(EVENT_ALL_ACCESS, FALSE, EVENT_NAME2);

	while (true)
	{
		ZeroMemory(szBufIn, BUFFER_SIZE);
		ZeroMemory(szBufOut, BUFFER_SIZE);

		WaitForSingleObject(hEvent2, INFINITE);
		memcpy(szBufOut, pBeginAddress, BUFFER_SIZE);
		cout << "Shared Memory:" << szBufOut << endl;

		cout << "Pls:";
		cin.getline(szBufIn, BUFFER_SIZE);
		memcpy(pBeginAddress, szBufIn, BUFFER_SIZE);

		ResetEvent(hEvent2);
		SetEvent(hEvent1);
	}

	CloseHandle(hEvent1);
	CloseHandle(hEvent2);
	CloseHandle(hFile);
	UnmapViewOfFile(hMap);
	CloseHandle(hMap);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
