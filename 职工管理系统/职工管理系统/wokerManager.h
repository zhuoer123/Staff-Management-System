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
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void showMenu();

	//�˳�����
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�������ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_EMP();

	//��������
	~WorkerManager();
};