// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "RecvThread.h"

#pragma comment(lib,"ws2_32.lib")

int main()
{
	int nRes = -1;

	WSADATA wd = { 0 };
	WSAStartup(0x0202,&wd);

	//Creat listen Socket
	SOCKET SocketListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketListen == INVALID_SOCKET)
	{
		cout << "Failed to Create Socket listen" << endl;

		return nRes;
	}

	//Create Address
	sockaddr_in addrServer = { 0 };
	
	hostent * pHostent = NULL;
	pHostent = gethostbyname("");
	if (!pHostent)
	{
		cout << "Failed to get the host" << endl;

		return nRes;
	}

	addrServer.sin_addr = *(in_addr*)pHostent->h_addr_list[0];
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(5050);

	//Bind SocketListen and addrServer
	if (SOCKET_ERROR == bind(SocketListen, (sockaddr*)&addrServer, sizeof(addrServer)))
	{
		cout << "Failed to bind" << endl;

		return nRes;
	}

	//Listen 
	if(SOCKET_ERROR == listen(SocketListen,5))
	{ 
		cout << "Failed to listen" << endl;

		return nRes;
	}

	//accept
	SOCKET SocketClient = { 0 };
	sockaddr_in addrClient = { 0 };
	int nLen = sizeof(sockaddr_in);
	SocketClient = accept(SocketListen, (sockaddr*)&addrClient, &nLen);
	if (INVALID_SOCKET == SocketClient)
	{
		cout << "Failed to accept" << endl;

		return nRes;
	}

	//Recv and Send 
	char* pIP = NULL;

	//Create Thread
	DWORD dwThreadID1 = 0;
	DWORD dwThreadID2 = 0;
	HANDLE hRecvThread;
	HANDLE hSendThread;

	pIP = inet_ntoa(*(in_addr*)&addrClient);
	if (!pIP)
		return nRes;

	cout << "ÐÂÁ¬½Ó£º" << pIP << endl;

	hRecvThread = CreateThread(NULL, 0, RecvThread, (LPVOID)SocketClient, 0, &dwThreadID1);
	CloseHandle(hRecvThread);
	hSendThread = CreateThread(NULL, 0, SendThread, (LPVOID)SocketClient, 0, &dwThreadID2);
	CloseHandle(hSendThread);

	getchar();

	WSACleanup();
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
