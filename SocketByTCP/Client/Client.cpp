// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#pragma comment(lib,"ws2_32.lib")

int main()
{
	int nRes = -1;

	WSADATA wd = { 0 };
	WSAStartup(0x0202, &wd);

	//Socket Client
	SOCKET SocketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	sockaddr_in addrServer = { 0 };
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = inet_addr("192.168.36.1");
	addrServer.sin_port = htons(5050);

	char szBuf[2048] = { 0 };
	nRes = connect(SocketClient, (sockaddr*)&addrServer, sizeof(SOCKADDR_IN));
	while (1)
	{
		
		if (!nRes)
		{
			cout << "Self:";
			cin >> szBuf;
			send(SocketClient, szBuf, 2048, 0);
		}
	}

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
