#pragma once
#include<iostream>
#include<string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

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

	//保存至文件
	void save();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_EMP();

	//判断职工是否存在  如果存在，返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//删除职工
	void Del_EMP();

	//修改职工
	void Mod_Emp();
	
	//查找职工
	void Find_Emp();

	//职工排序
	void sort_Emp();

	//清空
	void clear_Emp();

	//析构函数
	~WorkerManager();
};