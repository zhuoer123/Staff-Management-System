#pragma once
#include<iostream>
#include "worker.h"
#include<string>

using namespace std;

class Employee : public Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptNam();

	Employee(int Id, string name, int dId);
};