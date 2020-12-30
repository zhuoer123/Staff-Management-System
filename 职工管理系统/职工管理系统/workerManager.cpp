#include<iostream>
#include "wokerManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		//初始化属性
		//初始化记录人数
        this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//2.文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;

		//初始化属性
        //初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//3.文件存在 并记录人数
	int num = this->get_EmpNum();
	cout << "职工个数为：" << num << endl;
	//更新成员属性
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];

	this->init_Emp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< " 姓名：" << this->m_EmpArray[i]->m_Name
			<< " 部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs(FILENAME, ios::in);

	int num = 0;

	int Id;
	string name;
	int dId;

	while (ifs >> Id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs(FILENAME, ios::in);

	int num = 0;

	int Id;
	string name;
	int dId;

	Worker* worker = NULL;

	int index = 0;

	while (ifs >> Id && ifs >> name && ifs >> dId)
	{
		if (dId == 1)
		{
			worker = new Employee(Id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(Id, name, dId);
		}
		else
		{
			worker = new Boss(Id, name, dId);
		}
	    this->m_EmpArray[index] = worker;
	    index++;
	}

	ifs.close();

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

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名职工" << endl;

		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "数据有误" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	
	ofs.close();
}

//显示职工
void WorkerManager::Show_EMP()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或数据为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//判断职工是否存在 如果存在，返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1; //初始化为 不存在
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到这个员工
			index = i;
			break;
		}
	
	}
	return index;
}

//删除职工
void WorkerManager::Del_EMP()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) //职工存在
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			//数据同步更新到文件中
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到" << id << "号的职工，请输入新的职工号：" << endl;

			//防止编号重复
			while (1)
			{
				cin >> newId;
				if (this->IsExist(newId) == -1)
				{
					break;
				}
				cout << "编号已存在，请重新输入：" << endl;				
			}

			
			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}

	}

	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按成员编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			cout << "请输入要查找的成员编号：" << endl;
			int Id = 0;
			cin >> Id;

			int index = this->IsExist(Id);
			if (index == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "查找成功，该成员信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的成员姓名：" << endl;
			string name; 
			cin >> name;

			bool flag = false;  //标志量  存在为 true，不存在为falsse

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号"
						<< this->m_EmpArray[i]->m_Id 
						<< "的信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

//职工排序
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
		//system("pause");
		//system("cls");
	}

	cout << "请选择排序方式" << endl;
	cout << "1.按职工编号进行升序" << endl;
	cout << "2.按职工编号进行降序" << endl;

	int select = 0;
	cin >> select;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		int minOrmax = i;
		for (int j = i + 1; j < this->m_EmpNum; j++)
		{
			if (select == 1) //升序
			{
				if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			else  //降序
			{
				if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
		}

		if (i != minOrmax)
		{
			Worker* temp = this->m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[minOrmax];
			m_EmpArray[minOrmax] = temp;

		}

	}

	cout << "排序成功！排序后的结果为：" << endl;
	this->save();
	this->Show_EMP();

}

//清空
void WorkerManager::clear_Emp()
{
	cout << "确定删除？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //如果存在删除文件并重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}

			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功！" << endl;

	}

	system("pause");
	system("cls");

}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

