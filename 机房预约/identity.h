#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"globalfile.h"

using namespace std;
class identity
{
public:
	virtual void operMenu() = 0;
	string m_name;
	string m_Pwd;
};