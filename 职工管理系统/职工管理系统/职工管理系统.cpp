#include<iostream>
#include "wokerManager.h"

using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	//���Դ��룺
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.showMenu();	

		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:    //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:    //����ְ��
			wm.Add_Emp();
			break;
		case 2:    //��ʾְ��
			wm.Show_EMP();
			break;
		case 3:    //ɾ��ְ��
			wm.Del_EMP();
			break;
		case 4:    //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:    //����ְ��
			break;
		case 6:    //����ְ��
			break;
		case 7:    //����ĵ�
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	system("pause");
	return 0;
}