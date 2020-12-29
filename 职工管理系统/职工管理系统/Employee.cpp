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
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptNam()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

//获取岗位名称
string Employee::getDeptNam()
{
	return string("员工");
}