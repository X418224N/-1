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
	void applyOrder();//申请预约
	void showMyOrder();//查看我的预约
	void showallorder();//查看所有预约
	void cancelorder();//取消预约
	vector<computerroom>vcom;
	int m_id;

};
