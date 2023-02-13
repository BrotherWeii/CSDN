// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <windows.h>

#define HASHTABLESIZE (10)
BOOL WideChar2MultiByte(const wchar_t* pstrSrc, string& strDest);


const char* szStr[10] = {"2","3","4","5","6","7","8","9","11","1"};
void Test(int*& nItems)
{
	if (!nItems)
	{
		cout << "test" << endl;
	}
}

unsigned short Hash(const char*pstr);

int main()
{
	int* nItems = NULL;
	Test(nItems);

	int* psda = NULL;
	int ntep = *psda;

	int nIndex = 0;
	cout << szStr[nIndex + 4] << endl;
	wstring strWideChar = L"";
	string strMultiByte = "";
	WideChar2MultiByte(strWideChar.c_str(), strMultiByte);

	string str = "123";
	cout << "Size: " << str.size() << "Len: " << str.length() << endl;

	unsigned short uIndex = 0;
	int i = 0;

	while (i < HASHTABLESIZE)
		std::cout << Hash(szStr[i++]) << std::endl;

	getchar();
}

BOOL WideChar2MultiByte(const wchar_t* pstrSrc, string& strDest)
{
	int nMultiByteLen = 0;
	char* pstrMultiByte = NULL;

	nMultiByteLen = WideCharToMultiByte(CP_UTF8, 0, pstrSrc, -1, NULL, 0, NULL, NULL);
	if (nMultiByteLen)
	{
		pstrMultiByte = new char[nMultiByteLen + 1]();
		if (pstrMultiByte)
		{
			WideCharToMultiByte(CP_UTF8, 0, pstrSrc, -1, pstrMultiByte, nMultiByteLen, NULL, NULL);
			strDest = pstrMultiByte;

			delete[] pstrMultiByte;

			return TRUE;
		}
	}

	return FALSE;
}

unsigned short Hash(const char * pstr)
{
	unsigned short uHashValue = 0;
	unsigned short ch = 0;

	if (nullptr == pstr)
		return 0;

	while (ch = (unsigned short)*pstr++)
		uHashValue += ch;

	return uHashValue %  HASHTABLESIZE;
}
