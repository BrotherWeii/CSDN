// SinglePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;

//����ʽ
class CSingletonLazy
{
public://�ṩȫ�ֵĽӿڻ�ȡ����

	static CSingletonLazy* GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new CSingletonLazy();
		}

		return m_Instance;
	}

private://˽�л�����͸�ֵ���������

	CSingletonLazy() {};
	CSingletonLazy(CSingletonLazy&) {};
	CSingletonLazy& operator=(CSingletonLazy&) {};


private:
	static CSingletonLazy* m_Instance;
};

CSingletonLazy* CSingletonLazy::m_Instance = NULL;

//����ʽ
class CSingletonHungry
{
public:
	static CSingletonHungry* GetInstance()
	{
		return m_Instance;
	}

private:
	CSingletonHungry() {};
	CSingletonHungry(CSingletonHungry&);
	CSingletonHungry& operator=(CSingletonHungry&);

private:
	static CSingletonHungry* m_Instance;
};

CSingletonHungry* CSingletonHungry::m_Instance = new CSingletonHungry();

//�ֲ���̬����
class CSingleton
{
public:
	static CSingleton* GetInstance()
	{
		static CSingleton s_obj;

		return &s_obj;
	}
	
private:
	CSingleton() {};

public:	//C++11
	CSingleton(CSingleton&) = delete;
	CSingleton& operator = (CSingleton&) = delete;
};

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << CSingleton::GetInstance() << endl;
		cout << CSingletonLazy::GetInstance() << endl;
		cout << CSingletonHungry::GetInstance() << endl;
	}
}

