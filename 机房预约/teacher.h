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
	virtual void operMenu();//�˵�����
	void showallorder();//�鿴����ԤԼ
	void validorder();//���ԤԼ
	int m_empid;//���ұ��
};
