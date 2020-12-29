#pragma once
#include<iostream>
#include<string>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:

	Boss(int Id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptNam();

};