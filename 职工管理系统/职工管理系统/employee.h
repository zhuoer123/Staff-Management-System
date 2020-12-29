#pragma once
#include<iostream>
#include "worker.h"
#include<string>

using namespace std;

class Employee : public Worker
{
public:
	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptNam();

	Employee(int Id, string name, int dId);
};