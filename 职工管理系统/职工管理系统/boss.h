#pragma once
#include<iostream>
#include<string>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:

	Boss(int Id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptNam();

};