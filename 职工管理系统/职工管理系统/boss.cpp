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

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptNam()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::getDeptNam()
{
	return string("老板");
}