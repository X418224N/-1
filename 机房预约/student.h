#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include<fstream>
#include"computerroom.h"
#include"orderfile.h"
using namespace std;
class student:public identity
{
public:
	student();
	student(int id, string name, string pwd);
	virtual void operMenu();
	void applyOrder();//����ԤԼ
	void showMyOrder();//�鿴�ҵ�ԤԼ
	void showallorder();//�鿴����ԤԼ
	void cancelorder();//ȡ��ԤԼ
	vector<computerroom>vcom;
	int m_id;

};
