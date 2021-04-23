#include <iostream>
using namespace std;
#include "Http/WinHttp/URL/CrackURL.h"
using namespace DownLoader;
#include "Thread/Lock/AutoLock.h"

void TestURLCarcker();//PASS
void TestAutoLock();



int main()
{
	//TestURLCarcker();

	return 0;
}

void TestURLCarcker()
{
	const wchar_t* strURL = L"http://172.16.9.100/restful/APB2016EBF1128X32WINAP001.zip";
	CCrackURL::GetInstance()->CrackURL(strURL);
	CURLModel* pModel = CCrackURL::GetInstance()->GetModel();
}

void TestAutoLock()
{
	CMutux MutuxLock;
	MutuxLock.Create(NULL,FALSE);
	CAutoLock(&MutuxLock);
}
