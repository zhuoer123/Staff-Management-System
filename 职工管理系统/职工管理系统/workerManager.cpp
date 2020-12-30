#include<iostream>
#include "wokerManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;

		//��ʼ������
		//��ʼ����¼����
        this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//2.�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;

		//��ʼ������
        //��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//3.�ļ����� ����¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	//���³�Ա����
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];

	this->init_Emp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< " ������" << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

//ͳ���ļ�������
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

//��ʼ��Ա��
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
	cout << "***** ��ӭʹ��ְ������ϵͳ *****" << endl;
	cout << "******** 0.�˳�����ϵͳ ********" << endl;
	cout << "******** 1.����ְ����Ϣ ********" << endl;
	cout << "******** 2.��ʾְ����Ϣ ********" << endl;
	cout << "******** 3.ɾ����ְְ�� ********" << endl;
	cout << "******** 4.�޸�ְ����Ϣ ********" << endl;
	cout << "******** 5.����ְ����Ϣ ********" << endl;
	cout << "******** 6.���ձ������ ********" << endl;
	cout << "******** 7.��������ĵ� ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//�����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum; 

		//�����¿ռ�
		Worker ** newSpace = new Worker*[newSize];

		//��ԭ���ռ������ݿ������¿ռ���
		if(this->m_EmpArray != NULL)
		{
			for (int i = 0; i < newSize; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ����������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;

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

			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

//�����ļ�
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

//��ʾְ��
void WorkerManager::Show_EMP()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ�����Ϊ��" << endl;
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

//�ж�ְ���Ƿ���� ������ڣ�����ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1; //��ʼ��Ϊ ������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ����Ա��
			index = i;
			break;
		}
	
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::Del_EMP()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) //ְ������
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			//����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽" << id << "�ŵ�ְ�����������µ�ְ���ţ�" << endl;

			while (1)
			{
				cin >> newId;
				/*int Ret = this->IsExist(newId);
				cout << Ret << endl;*/
				if (this->IsExist(newId) != -1)
				{
					break;
				}
				else
				{
					cout << "����Ѵ��ڣ����������룺" << endl;
				}
				
			}

			
			cout << "�������µ�������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}

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

