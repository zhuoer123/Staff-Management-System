#include<iostream>
#include "wokerManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	//初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}


void WorkerManager::showMenu()
{
	cout << "********************************" << endl;
	cout << "***** 欢迎使用职工管理系统 *****" << endl;
	cout << "******** 0.退出管理系统 ********" << endl;
	cout << "******** 1.增加职工信息 ********" << endl;
	cout << "******** 2.显示职工信息 ********" << endl;
	cout << "******** 3.删除离职职工 ********" << endl;
	cout << "******** 4.修改职工信息 ********" << endl;
	cout << "******** 5.查找职工信息 ********" << endl;
	cout << "******** 6.按照编号排序 ********" << endl;
	cout << "******** 7.清空所有文档 ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算新空间的大小
		int newSize = this->m_EmpNum + addNum; 

		//开辟新空间
		Worker ** newSpace = new Worker*[newSize];

		//将原来空间下数据拷贝到新空间下
		if(this->m_EmpArray != NULL)
		{
			for (int i = 0; i < newSize; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加" << addNum << "名职工" << endl;

	}
	else
	{
		cout << "数据有误" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{

}

