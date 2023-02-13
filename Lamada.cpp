// Lamada.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class A
{
public:

	 A() { cout << "Base A"; }
};

class B : public A
{
public:
	B() { cout << "Derive B"; }
};



int main()
{
	//A *pA = new B;

	cout << sizeof(unsigned __int64) << endl;
	cout << sizeof(int) << endl;

	cout << LLONG_MIN << endl;
	/*a
	wchar_t* pstr = new wchar_t[0];

	//Lamada expression
	//auto pfn = [Capture parameters list](parameters list)->return type{function body};
	 auto pfn1 = [](int a) {cout << a << endl;};
	 pfn1(1);
	
	//Capture parameters
	 int x = 1024;
	 auto pfn2 = [x]() {cout << x << endl; };
	 pfn2();

	 //Capture Reference
	 int  a = 123;
	 auto pfn3 = [&]() {cout << a << endl; };
	 pfn3();

	 //Capture Value
	 auto pfn4 = [=]() {cout << x << endl; };
	 pfn4();
	 */
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
