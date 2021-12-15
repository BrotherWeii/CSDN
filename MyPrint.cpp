// MyPrint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//知识点：函数压栈，指针偏移


void MyPrintf(string str, ...);

int main()
{
	//printf("%s%d", "StringTest", 10);
	MyPrintf("%s%d", "StringTest", 10);
}


void MyPrintf(string str, ...)
{
	int nPos		= -1;
	void* pVoid		= NULL;
	string strTemp  = str;

	nPos = str.find_first_of("%");
	pVoid = &str + 1;

	while (nPos != -1)
	{
		switch (strTemp[nPos+1])
		{
			case 's':
			{
				cout << *(char**)pVoid;
				pVoid = (char**)pVoid + 1;
				break;
			}
			case'd':
			{
				cout << *(int*)pVoid;
				pVoid = (int*)pVoid + 1;
				break;
			}
			default:
			{
				cout << "Invalid Type!" << endl;
				break;
			}
		}

		strTemp = strTemp.substr(nPos+1);
		nPos = strTemp.find_first_of("%");
	}
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
