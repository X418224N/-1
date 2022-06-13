#pragma once
#include<iostream>
#include"identity.h"
#include"orderfile.h"
#include<fstream>
#include"computerroom.h"
#include<vector>
using namespace std;
class teacher :public identity
{
public:
	teacher();
	teacher(int empid, string name, string pwd);
	virtual void operMenu();//菜单界面
	void showallorder();//查看所有预约
	void validorder();//审核预约
	int m_empid;//教室编号
};
