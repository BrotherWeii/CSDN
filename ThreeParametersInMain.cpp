#include <iostream>
using namespace std;


int main(int argc,char**argv, char**evn)
{
	//��������������
	//argc���������еĲ�������
	//argv��ָ�����飬�洢�������еľ��������
	//		argv[0]����ǰ��ִ���ļ�����·��
	//		argv[1]: ��һ������
	//		argv[2]: ����...
	//evn: ָ�����飬����������evp[end] = NULL;

	//---ʵ�ּӼ��˳�---
	//��������������������Ϊ Test.exe a 11 12

	//			  argv[0]: //��ִ���ļ�����·��
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

	//��ӡ���еĻ�������
	for (int i = 0; evn[i]!=NULL; i++)
	{
		cout << i << ": " << evn[i] << endl;
	}

	return 1;
}