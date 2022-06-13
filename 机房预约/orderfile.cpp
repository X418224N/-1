#include"orderfile.h"
orderfile::orderfile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string data;//日期
	string interval;//时间段
	string stuid;//学生编号
	string roomid;//机房编号
	string stuname;
	string status;//预约状态
	this->m_size = 0;
	while (ifs >> data && ifs >> interval && ifs >> stuid && ifs >>stuname&&ifs>> roomid && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;
		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();		
	/*for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end(); ++it)
	{
		cout << "记录" << it->first << "value=" << endl;
		for (map<string, string > ::iterator mit = (*it).second.begin(); mit != (*it).second.end(); ++mit)
		{
			cout << "key=" << mit->first << "value="<< mit->second << " ";
		}
		cout << endl;
	}*/
}
void orderfile::updateorder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
		for (int i = 0; i < this->m_size; i++)
		{
			ofs << "data:" << this->m_orderdata[i]["data"] << " ";
			ofs << "interval:" << this->m_orderdata[i]["interval"] << " ";
			ofs << "stuid:" << this->m_orderdata[i]["stuid"] << " ";
			ofs << "stuname:" << this->m_orderdata[i]["stuname"] << " ";
			ofs << "roomid:" << this->m_orderdata[i]["roomid"] << " ";
			ofs << "status:" << this->m_orderdata[i]["status"] << " ";
		}
		ofs.close();
}