#include<iostream>
#include<string>
#include "employee.h"

using namespace std;

Employee::Employee(int Id, string name, int dId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptNam()
		<< "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::getDeptNam()
{
	return string("Ա��");
}