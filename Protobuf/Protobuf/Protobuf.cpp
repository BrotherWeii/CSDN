// Protobuf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.pb.h"
#include <fstream>
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	tutorial::Person Person1;
	Person1.set_strname("Aijiawei");
	Person1.set_nage(23);
	Person1.set_stremail("13387169596@qq.com");

	fstream file1;
	file1.open("C:\\Users\\apeon\\Desktop\\Test.txt", ios::out|ios::binary|ios::trunc);
	
	if (!Person1.SerializeToOstream(&file1))
	{
		cerr << "error" << endl;
	}
	file1.close();

	fstream file2;
	file2.open("C:\\Users\\apeon\\Desktop\\Test.txt", ios::in|ios::binary);
	tutorial::Person Person2;
	if (!Person2.ParseFromIstream(&file2))
	{
		cerr << "error" <<endl;
	}
	
	cout <<Person2.strname().c_str() << '\n'
	     <<Person2.nage() << '\n'
		 <<Person2.stremail().c_str();
	return 0;
}

