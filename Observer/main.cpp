// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include "Player.h"

int main()
{
	CGame* Gamer = new CGame();

	CPlayer* player[5] = { 0 };
	char szBuf[64] = { 0 };
	for (int i=0;i<5;i++)
	{
		_itoa_s(i, szBuf, 64, 10);
		player[i] = new CPlayer(szBuf);
		(player[i])->SetGusNum(i);
		Gamer->Attach(player[i]);
	}
	
	Gamer->Notify();
	Gamer->Notify();
	Gamer->Notify();
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
