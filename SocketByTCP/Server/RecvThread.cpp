#include "pch.h"

char g_RecvBuf[1024 * 2] = { 0 };
char g_SendBuf[1024 * 2] = { 0 };

DWORD WINAPI RecvThread(LPVOID pVoidParam)
{
	int nRes = -1;
	SOCKET SockClient = (SOCKET)pVoidParam;

	while(1)
	{
		nRes = recv(SockClient, g_RecvBuf, 2048, 0);
		if (SOCKET_ERROR == nRes)
		{
			cout << "Failed to recv" << endl;

			return nRes;
		}
		else
		{
			cout << "-------------------" << endl;
			cout << g_RecvBuf << endl;
			cout << "-------------------" << endl;
		}
	}
	
}

DWORD WINAPI SendThread(LPVOID pVoidParam)
{
	while (true)
	{
		SOCKET SockClient = (SOCKET)pVoidParam;

		cout << "ÇëÊäÈë:";
		cin >> g_SendBuf;
		send(SockClient, g_SendBuf, 2048, 0);
	}
	
}