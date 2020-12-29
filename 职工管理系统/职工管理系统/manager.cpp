#include<iostream>
#include<string>
#include "manager.h"

using namespace std;

Manager::Manager(int Id, string name, int dId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptNam()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

//获取岗位名称
string Manager::getDeptNam()
{
	return string("经理");
}