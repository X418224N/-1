#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerroom.h"
class manager :public identity
{
public:
	manager();
	manager(string name, string pwd);
	virtual void operMenu();
	void addperson();
	void showperson();
	void showcomputer();
	void cleanfile();
	void initvector();
	void deleteperson();
	bool checkrepeat(int id, int type);
	vector<student>vstu;
	
	vector<teacher>vtea;
	vector<computerroom>vcom;
};