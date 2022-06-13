#pragma once
#include<iostream>
#include<vector>
#include"computerRoom.h"
#include"globalfile.h"
#include<map>
#include<fstream>
using namespace std;
#include<string>
class orderfile
{
public:
	orderfile();//构造函数
	void updateorder();//更新预约记录
	map<int,map<string,string>>m_orderdata;//记录的容器 key为记录的条数,value为具体记录的键值对信息 里层map中key为属性，value为实值
	int m_size;//预约记录条数
};