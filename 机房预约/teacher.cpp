#include"teacher.h"
teacher::teacher()
{

}
teacher::teacher(int empid,string name,string pwd)
{
	this->m_empid = empid;
	this->m_name = name;
	this->m_Pwd = pwd;
}
void teacher::operMenu()
{
	cout << "欢迎教室" << this->m_name << "登录" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.注销账号" << endl;
}
void teacher::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " ";
		cout << "预约日期:周" << of.m_orderdata[i]["data"] << " ";
		cout << "时段:" << (of.m_orderdata[i]["interval"] = "1" ? "上午" : "下午") << " ";
		cout << "学号:" << of.m_orderdata[i]["stuid"] << " ";
		cout << "学生姓名:" << of.m_orderdata[i]["stuname"] << " ";
		cout << "机房号:" << of.m_orderdata[i]["roomid"] << " ";
		string status = "状态:";
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void teacher::validorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "带审核的预约记录如下" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{

		if (of.m_orderdata[i]["status"] == "1")
		{

			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期:周" << of.m_orderdata[i]["date"];
			cout << "时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房:" << of.m_orderdata[i]["roomid"];
			string status = "状态:";
			if (of.m_orderdata[i]["status"] == "1")
			{
				status+="审核中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，输入0返回"<<endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核的结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderdata[v[select = 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "审核完毕" << endl;
				break;
			}
		}
	}


}

