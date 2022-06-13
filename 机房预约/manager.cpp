#include"manager.h"
manager::manager()
{

}//默认构造
manager::manager(string name, string pwd)
{
	this->m_name = name;
	this->m_Pwd = pwd;
	this->initvector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerroom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房数量为：" << vcom.size() << endl;
}//有参构造
void manager::operMenu()
{
	cout << "欢迎管理员" << this->m_name << "登录" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "5.删除用户" << endl;
	cout << "0.注销登录" << endl;
}
void manager::addperson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	string filename;
	string tip;
	ofstream ofs;
	string errprtip;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "请输入学号";
			errprtip = "学号已重复或不在范围内，请重新输入";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			 tip="请输入教职工号" ;
			 errprtip = "职工编号已重复或不在范围内，请重新输入";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		
		bool ret = checkrepeat(id, select);
		if (ret)
		{
			cout << errprtip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加用户成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initvector();//调用初始化接口，从新获取文件中接口
}//添加账号
void manager::showperson()
{
	cout << "请输入你想查看的信息" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "学生信息如下" << endl;
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			cout << "学生的编号：" << it->m_id << "学生的姓名是:" << it->m_name << "学生的密码是：" << it->m_Pwd << endl;
		}
	}
	else if (select == 2)
	{
		cout << "教师信息如下" << endl;
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			cout << "教室的编号：" << it->m_empid<< "学生的姓名是:" << it->m_name << "学生的密码是：" << it->m_Pwd << endl;
		}
	}
	/*system("pause");
	system("cls");*/
}//查看账号
void manager::showcomputer()
{
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号：" << it->m_comid << "机房容量：" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}//查看机房信息
void manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
void manager::initvector()//初始化
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vstu.push_back(s);
	}
	cout << "当前学生数量为:" << vstu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vtea.push_back(t);
	}
	cout << "当前老师数量为:" << vtea.size() << endl;
	ifs.close();
}
void manager::deleteperson()
{
	ifstream ifs;
	
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	cout << "0.退出程序" << endl;
	int select = 0;
	int ret=0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			ifs.open(STUDENT_FILE, ios::in);
			student s;
			
			/*while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_Pwd)
			{
				cout << "学号:" << s.m_id <<" " << "姓名:" << s.m_name << " " << "密码:" << s.m_Pwd << endl;
			}*/
			for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
			{	
				cout << "学生的编号：" << it->m_id << "学生的姓名是:" << it->m_name << "学生的密码是：" << it->m_Pwd << endl;
			}
			cout << "请输入你想要删的学生的学号:" << endl;
			while (true)
			{
				cin >> ret;
				ifstream ifs;
				ofstream ofs;
				ifs.open(STUDENT_FILE, ios::binary | ios::out | ios::in);
				ofs.open(TEMP_FILE, ios::binary | ios::out);
				while(ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_Pwd)
				{
					if (s.m_id == ret)
					{
						cout << "删除成功" << endl;
						continue;
					}
					else if (ret == 0)
					{
						
					}
					
					
					ofs << s.m_id << " " << s.m_name << " " << s.m_Pwd << endl;
					
				}
				ifs.close();
				ofs.close();
				/*ofstream ofs;
				ifstream ifs;*/
				ofs.open(STUDENT_FILE, ios::binary | ios::out);
				ifs.open(TEMP_FILE, ios::binary | ios::out | ios::in);
				while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_Pwd)
				{
					ofs << s.m_id << " " << s.m_name << " " << s.m_Pwd << endl;
				}
				ofs.close();
				ifs.close();
				break;
				
			}
			break;
		}
		else if (select == 2)
		{
			ifs.open(TEACHER_FILE, ios::in);
			teacher t;
			while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_Pwd)
			{
				cout << "学号职工编号:" << t.m_empid << " " << "姓名:" << t.m_name << " " << "密码:" << t.m_Pwd << endl;
			}
			cout << "请输入您想要删除的职工编号" << endl;
			while (true)
			{
				cin >> ret;
				ifstream ifs;
				ofstream ofs;
				ifs.open(TEACHER_FILE, ios::binary | ios::out | ios::in);
				ofs.open(TEMP_FILE, ios::binary | ios::out);
				while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_Pwd)
				{
					if (t.m_empid == ret)
					{
						cout << "删除成功" << endl;
						continue;
					}
					else if (ret == 0)
					{

					}
					else
					{
						cout << "你要删除的教师不存在" << endl;
						break;
					}
					ofs << t.m_empid << " " << t.m_name << " " << t.m_Pwd << endl;
				}
				ifs.close();
				ofs.close();
				ofs.open(TEACHER_FILE, ios::binary | ios::out);
				ifs.open(TEMP_FILE, ios::binary | ios::out | ios::in);
				while (ifs>>t.m_empid&&ifs>>t.m_name&&ifs>>t.m_Pwd)
				{
					ofs << t.m_empid << " " << t.m_name << " " << t.m_Pwd << endl;
				}
				ofs.close();
				ifs.close();
				break;
			}
			break;
		}
		else if (select == 0)
		{
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "你的输入有误请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
	this->initvector();
}
bool manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->m_id||id<=0)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->m_empid||id<=0)
			{
				return true;
			}
		}
	}
	return false;
 }