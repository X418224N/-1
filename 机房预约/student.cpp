#include"student.h"
student::student()
{

}
student::student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Pwd = pwd;
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerroom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	cout << "机房数量为:" << vcom.size() << endl;
}
void student::operMenu()
{
	cout << "欢迎学生" << this->m_name << "登录" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看本人预约" << endl;
	cout << "3.查看所有人预约" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.退出登录" << endl;

}
void student::applyOrder()//申请预约
{
	cout << "机房开放的时间为周一至周五" << endl;
	cout << "请输入预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int data = 0;//日期
	int interval = 0;//时间段
	int roomid = 0;//机房编号
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "请输入申请预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_comid << "号机房的容量为:" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> roomid;
		if (roomid >= 1 && roomid <= 3)
		{
			break;
		}
		cout << "你输入有误，请重新输入" << endl;
	}
	cout << "预约成功!审核中" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << " interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomid:" << roomid << " ";
	ofs << "status:" << 1 << endl;//审核状态
	ofs.close();
	system("pause");
	system("cls");

}
void student::showallorder()//查看所有人预约
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << ",";
		cout << "预约日期: 周" << of.m_orderdata[i]["data"] << " ";
		cout << "时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号:" << of.m_orderdata[i]["stuid"] << " ";
		cout << "姓名:" << of.m_orderdata[i]["stuname"] << " ";
		cout << "机房号" << of.m_orderdata[i]["roomid"] << " ";
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
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void student::showMyOrder()//查看我的预约
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id)//将字符串转换为整形，string利用.c_str转换成const char * ,利用atoi(const char *)转换成int
		{
			cout << "预约日期: 周" << of.m_orderdata[i]["data"]<<" ";
			cout << "时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房号" << of.m_orderdata[i]["roomid"] << " ";
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
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
void student::cancelorder()//注销预约
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核记录或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;
	int index = 1;//代表编号
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))
		{
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")//筛选容器中符合条件的编号
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期:周" << of.m_orderdata[i]["date"];
				cout << "时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房号" << of.m_orderdata[i]["roomid"] << " ";
				string status = "状态:";
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select>=0&&select<=v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderdata[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "取消预约成功" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
