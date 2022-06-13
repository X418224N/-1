#include"manager.h"
manager::manager()
{

}//Ĭ�Ϲ���
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
	cout << "��������Ϊ��" << vcom.size() << endl;
}//�вι���
void manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_name << "��¼" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "5.ɾ���û�" << endl;
	cout << "0.ע����¼" << endl;
}
void manager::addperson()
{
	cout << "����������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
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
			tip = "������ѧ��";
			errprtip = "ѧ�����ظ����ڷ�Χ�ڣ�����������";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			 tip="�������ְ����" ;
			 errprtip = "ְ��������ظ����ڷ�Χ�ڣ�����������";
			break;
		}
		else
		{
			cout << "������������������" << endl;
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
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "����û��ɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initvector();//���ó�ʼ���ӿڣ����»�ȡ�ļ��нӿ�
}//����˺�
void manager::showperson()
{
	cout << "����������鿴����Ϣ" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "ѧ����Ϣ����" << endl;
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			cout << "ѧ���ı�ţ�" << it->m_id << "ѧ����������:" << it->m_name << "ѧ���������ǣ�" << it->m_Pwd << endl;
		}
	}
	else if (select == 2)
	{
		cout << "��ʦ��Ϣ����" << endl;
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			cout << "���ҵı�ţ�" << it->m_empid<< "ѧ����������:" << it->m_name << "ѧ���������ǣ�" << it->m_Pwd << endl;
		}
	}
	/*system("pause");
	system("cls");*/
}//�鿴�˺�
void manager::showcomputer()
{
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ�" << it->m_comid << "����������" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}//�鿴������Ϣ
void manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
void manager::initvector()//��ʼ��
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vstu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ:" << vstu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vtea.size() << endl;
	ifs.close();
}
void manager::deleteperson()
{
	ifstream ifs;
	
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	cout << "0.�˳�����" << endl;
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
				cout << "ѧ��:" << s.m_id <<" " << "����:" << s.m_name << " " << "����:" << s.m_Pwd << endl;
			}*/
			for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
			{	
				cout << "ѧ���ı�ţ�" << it->m_id << "ѧ����������:" << it->m_name << "ѧ���������ǣ�" << it->m_Pwd << endl;
			}
			cout << "����������Ҫɾ��ѧ����ѧ��:" << endl;
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
						cout << "ɾ���ɹ�" << endl;
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
				cout << "ѧ��ְ�����:" << t.m_empid << " " << "����:" << t.m_name << " " << "����:" << t.m_Pwd << endl;
			}
			cout << "����������Ҫɾ����ְ�����" << endl;
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
						cout << "ɾ���ɹ�" << endl;
						continue;
					}
					else if (ret == 0)
					{

					}
					else
					{
						cout << "��Ҫɾ���Ľ�ʦ������" << endl;
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
			cout << "���������������������" << endl;
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