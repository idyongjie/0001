#include"workerManage.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_num = 0;
		this->m_fileisempty = true;
		this->m_arr ;
		ifs.close();
		return;
	}
	//文件存在，数据为空
	char ch;
	ifs >> ch;
		if (ifs.eof())
		{
			this->m_num = 0;
			this->m_fileisempty = true;
			this->m_arr;
			ifs.close();
			return;
		}
		//文件存在，数据不为空
		int num = this->get_empmem();
		this->m_num = num;
		this->m_arr ;
		this->init_emp();
}
WorkerManager::~WorkerManager()
{

}
void WorkerManager::show_menu()
{
	cout << "***************************************" << endl;
	cout << "*********欢迎使用职工管理系统**********" << endl;
	cout << "***********  0.退出管理程序 ***********" << endl;
	cout << "***********  1.增加职工信息 ***********" << endl;
	cout << "***********  2.显示职工信息 ***********" << endl;
	cout << "***********  3.删除离职员工 ***********" << endl;
	cout << "***********  4.修改职工信息 ***********" << endl;
	cout << "***********  5.查找职工信息 ***********" << endl;
	cout << "***********  6.按照编号信息 ***********" << endl;
	cout << "***********  7.清空所有文档 ***********" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}
void WorkerManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::mem_save()
{
	fstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int ii = 0; ii < this->m_num; ii++)
	{
		ofs << m_arr[ii]->m_Id << " " << m_arr[ii]->m_Name << " " << m_arr[ii]->m_DeptId<<endl;
	}
	ofs.close();
}
void WorkerManager::men_read()
{
	//第一次使用，文件未创建；文件存在，但是数据被清空；文件存在，且保存有数据

}
void WorkerManager::Add_emp()
{
	cout << "请输入想要添加的职员数量：　" << endl;
	int addnum;//保存输入数量
	cin >> addnum;
	if (addnum < 0)
	{
		cout << "请输入正确的人数" << endl;
	}
	else {
		for (int ii = 0; ii < addnum; ii++)
		{
			int id;
			string name;
			int did;
			while (true)
			{
				cout << "请输入第" << ii + 1 << "个员工的编号" << endl;
				cin >> id;
				cout << endl;
				if (isexit(id)==-1)
					break;
				cout << "id重复！" << endl;
			}
			cout << "请输入第" << ii + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << ii + 1 << "个员工的部门" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new employee(id, name, did);
				break;
			case 2:
				worker = new manager(id, name, did);
				break;
			case 3:
				worker = new boss(id, name, did);
				break;
			default:
				break;
			}
			m_arr.push_back(worker);
			++m_num;
			this->m_fileisempty = false;
			cout << "添加成功" << endl;
		}
		WorkerManager::mem_save();
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
int WorkerManager::get_empmem()//统计文件中的人数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;//统计人数
	}
	ifs.close();
	return num;
}
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	worker* workee = NULL;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		if (did == 1)
			workee = new employee(id, name, did);
		else if (did == 2)
			workee = new manager(id, name, did);
		else
			workee = new boss(id, name, did);
		this->m_arr.push_back(workee);
	}
	ifs.close();

}
void WorkerManager::show_emp()
{
	if (this->m_fileisempty)
		cout << "文件不存在或者记录为空！" << endl;
	else if (this->m_num == 0)
		cout << "此时人数为0" << endl;
	else
	{
		for (int ii = 0; ii < m_num; ii++)
		{
			//利用多态调用程序接口
			this->m_arr[ii]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::isexit(int id) 
{
	int index = -1;
	for (int i = 0; i < this->m_num; i++)
		if (this->m_arr[i]->m_Id == id)
			index = i;
	return index;
}
void WorkerManager::del_emp()
{
	int id;
	cout << "请输入删除的id" << endl;
	cin >> id;
	if (isexit(id) == -1)
	{
		cout << "输入的id不存在" << endl;
	}
	else{
		this->m_arr.erase(m_arr.begin() + isexit(id) - 1);
		this->m_num--;

		cout << "删除成功" << endl;
	}
	this->mem_save();
	system("pause");
	system("cls");
}
void WorkerManager::change_emp()
{
	int id;
	cout << "请输入要修改员工的编号： ";
	cin >> id;
	int ii = isexit(id);
	if (ii == -1)
		cout << "此编号的员工不存在!" << endl;
	else {
		this->m_arr[ii]->showinfo();
		int id_;
		string name;
		int did;
		while (true) {
			cout << "请输入该员工的新编号： ";
			cin >> id_;
			cout << endl;
			if (isexit(id_)==-1||id_==id)
				break;
			else
			{
				cout << "编号重复！" << endl;
			}
		}
		cout << "请输入该员工的姓名： ";
		cin >> name;
		cout << endl;
		cout << "请输入该员工的部门编号： "<<endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> did;
		m_arr[ii]->m_Id = id_;
		m_arr[ii]->m_Name = name;
		m_arr[ii]->m_DeptId = did;
		cout << "修改成功" << endl;
		this->mem_save();
		system("pause");
		system("cls");
	}
}
