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
	cout << "��������Ϊ:" << vcom.size() << endl;
}
void student::operMenu()
{
	cout << "��ӭѧ��" << this->m_name << "��¼" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴����ԤԼ" << endl;
	cout << "3.�鿴������ԤԼ" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.�˳���¼" << endl;

}
void student::applyOrder()//����ԤԼ
{
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int data = 0;//����
	int interval = 0;//ʱ���
	int roomid = 0;//�������
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_comid << "�Ż���������Ϊ:" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> roomid;
		if (roomid >= 1 && roomid <= 3)
		{
			break;
		}
		cout << "��������������������" << endl;
	}
	cout << "ԤԼ�ɹ�!�����" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << " interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomid:" << roomid << " ";
	ofs << "status:" << 1 << endl;//���״̬
	ofs.close();
	system("pause");
	system("cls");

}
void student::showallorder()//�鿴������ԤԼ
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << ",";
		cout << "ԤԼ����: ��" << of.m_orderdata[i]["data"] << " ";
		cout << "ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��:" << of.m_orderdata[i]["stuid"] << " ";
		cout << "����:" << of.m_orderdata[i]["stuname"] << " ";
		cout << "������" << of.m_orderdata[i]["roomid"] << " ";
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
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void student::showMyOrder()//�鿴�ҵ�ԤԼ
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id)//���ַ���ת��Ϊ���Σ�string����.c_strת����const char * ,����atoi(const char *)ת����int
		{
			cout << "ԤԼ����: ��" << of.m_orderdata[i]["data"]<<" ";
			cout << "ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.m_orderdata[i]["roomid"] << " ";
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
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
void student::cancelorder()//ע��ԤԼ
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��˼�¼��ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;//������
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))
		{
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")//ɸѡ�����з��������ı��
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ����:��" << of.m_orderdata[i]["date"];
				cout << "ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "������" << of.m_orderdata[i]["roomid"] << " ";
				string status = "״̬:";
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼,0������" << endl;
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
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				break;
			}
		}
		cout << "��������,����������" << endl;
	}
	system("pause");
	system("cls");
}
