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
	orderfile();//���캯��
	void updateorder();//����ԤԼ��¼
	map<int,map<string,string>>m_orderdata;//��¼������ keyΪ��¼������,valueΪ�����¼�ļ�ֵ����Ϣ ���map��keyΪ���ԣ�valueΪʵֵ
	int m_size;//ԤԼ��¼����
};