#include<iostream>
#include<string>
#include "Boss.h"

using namespace std;

Boss::Boss(int Id, string name, int dId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptNam()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string Boss::getDeptNam()
{
	return string("�ϰ�");
}