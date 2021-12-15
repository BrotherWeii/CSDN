#pragma once
#include "ISubject.h"
#include <vector>


//Ŀ��
class CSubject : public ISubject
{
public:
	CSubject();
	~CSubject();

public:
	void Attach(IObserver* pObserver);		//��ӹ۲���
	void Dettach(IObserver* pObserver);		//ɾ���۲���
	void Notify();							//֪ͨ�۲���

public:
	std::vector<IObserver*> m_listObserver;	//�۲�����
};
