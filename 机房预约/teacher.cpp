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
	cout << "��ӭ����" << this->m_name << "��¼" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "0.ע���˺�" << endl;
}
void teacher::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " ";
		cout << "ԤԼ����:��" << of.m_orderdata[i]["data"] << " ";
		cout << "ʱ��:" << (of.m_orderdata[i]["interval"] = "1" ? "����" : "����") << " ";
		cout << "ѧ��:" << of.m_orderdata[i]["stuid"] << " ";
		cout << "ѧ������:" << of.m_orderdata[i]["stuname"] << " ";
		cout << "������:" << of.m_orderdata[i]["roomid"] << " ";
		string status = "״̬:";
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
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
		cout << "ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{

		if (of.m_orderdata[i]["status"] == "1")
		{

			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ����:��" << of.m_orderdata[i]["date"];
			cout << "ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << "����:" << of.m_orderdata[i]["roomid"];
			string status = "״̬:";
			if (of.m_orderdata[i]["status"] == "1")
			{
				status+="�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼������0����"<<endl;
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
				cout << "��������˵Ľ��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
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
				cout << "������" << endl;
				break;
			}
		}
	}


}

