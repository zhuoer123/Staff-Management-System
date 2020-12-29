#pragma once
#include<iostream>
#include<string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void showMenu();

	//退出操作
	void exitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//析构函数
	~WorkerManager();
};