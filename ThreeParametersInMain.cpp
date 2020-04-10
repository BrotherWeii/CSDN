#include <iostream>
using namespace std;


int main(int argc,char**argv, char**evn)
{
	//三个参数的作用
	//argc：命令行中的参数个数
	//argv：指针数组，存储命令行中的具体参数。
	//		argv[0]：当前可执行文件绝对路径
	//		argv[1]: 第一个参数
	//		argv[2]: 类推...
	//evn: 指针数组，环境变量。evp[end] = NULL;

	//---实现加减乘除---
	//假设我们命令行中输入为 Test.exe a 11 12

	//			  argv[0]: //可执行文件绝对路径
	char cCase = *argv[1]; //a
	int nA = atoi(argv[2]);//11
	int nB = atoi(argv[3]);//12

	switch (*argv[1])
	{
		case 'a':
		{
			cout << nA + nB << endl;
		}
		break;
	default:
		cout << "Default!" << endl;
		break;
	}

	//打印所有的环境变量
	for (int i = 0; evn[i]!=NULL; i++)
	{
		cout << i << ": " << evn[i] << endl;
	}

	return 1;
}