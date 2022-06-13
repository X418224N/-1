#include<iostream>
#include"globalfile.h"
#include<fstream>
#include<string>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
void managermenu(identity*& manager1)
{
	while (true)
	{
		manager1->operMenu();
		manager* man = (manager*)manager1;
		string select ;
		cin >> select;
		if (select == "1")
		{
			cout << "����˺�" << endl;
			man->addperson();
		}
		else if (select == "2")
		{
			cout << "�鿴�˺�" << endl;
			man->showperson();
		}
		else if (select == "3")
		{
			cout << "�鿴����" << endl;
			man->showcomputer();
		}
		else if (select == "4")
		{
			cout << "���ԤԼ" << endl;
			man->cleanfile() ;
		}
		else if (select == "5")
		{
			cout << "ɾ���û�" << endl;
			man->deleteperson();
		}
		else if (select == "0")
		{
			delete manager1;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "����������" << endl;
			system("pause");
		}

	}
}
void studentmenu(identity*& student1)
{
	while (true)
	{
		student1->operMenu();
		student* stu = (student*)student1;
		int select = 0;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showallorder();
		}
		else if (select == 4)//���ԤԼ
		{
			stu->cancelorder();
		}
		else
		{
			delete student1;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void teachermenu(identity*& teacher1)
{
	while (true)
	{
		teacher1->operMenu();
		teacher*tea = (teacher*)teacher1;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showallorder();//�鿴����ԤԼ
		}
		else if (select == 2)
		{
			tea->validorder();//���ԤԼ
		}
		else
		{
			delete teacher1;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void loginin(string filename, int type)
{
	identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
		
	}
	else if (type == 2)
	{
		cout << "���������ְ�����" << endl;
		cin >> id;
		
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	if (type == 1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				teachermenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fname;
		string fpwd;
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( name == fname && pwd == fpwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new manager( name, pwd);
				managermenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա"<<endl;
		cout << "0.�˳�ϵͳ" << endl;
		cout << "���������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			loginin(STUDENT_FILE, 1);
			break;
		case 2:
			loginin(TEACHER_FILE, 2);
			break;
		case 3:
			loginin(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "���������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}