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
			cout << "添加账号" << endl;
			man->addperson();
		}
		else if (select == "2")
		{
			cout << "查看账号" << endl;
			man->showperson();
		}
		else if (select == "3")
		{
			cout << "查看机房" << endl;
			man->showcomputer();
		}
		else if (select == "4")
		{
			cout << "清空预约" << endl;
			man->cleanfile() ;
		}
		else if (select == "5")
		{
			cout << "删除用户" << endl;
			man->deleteperson();
		}
		else if (select == "0")
		{
			delete manager1;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "请重新输入" << endl;
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
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看本人预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showallorder();
		}
		else if (select == 4)//清空预约
		{
			stu->cancelorder();
		}
		else
		{
			delete student1;
			cout << "注销成功" << endl;
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
			tea->showallorder();//查看所有预约
		}
		else if (select == 2)
		{
			tea->validorder();//审核预约
		}
		else
		{
			delete teacher1;
			cout << "注销成功!" << endl;
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
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
		
	}
	else if (type == 2)
	{
		cout << "请输入你的职工编号" << endl;
		cin >> id;
		
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
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
				cout << "学生验证登录成功" << endl;
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
				cout << "教师验证登录成功" << endl;
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
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new manager( name, pwd);
				managermenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "1.学生" << endl;
		cout << "2.老师" << endl;
		cout << "3.管理员"<<endl;
		cout << "0.退出系统" << endl;
		cout << "请输入你的选择" << endl;
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "你的输入有误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}