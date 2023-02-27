#include"workerManage.h"

WorkerManager::WorkerManager()
{
	//�ļ�������
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
	//�ļ����ڣ�����Ϊ��
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
		//�ļ����ڣ����ݲ�Ϊ��
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
	cout << "*********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "***********  0.�˳�������� ***********" << endl;
	cout << "***********  1.����ְ����Ϣ ***********" << endl;
	cout << "***********  2.��ʾְ����Ϣ ***********" << endl;
	cout << "***********  3.ɾ����ְԱ�� ***********" << endl;
	cout << "***********  4.�޸�ְ����Ϣ ***********" << endl;
	cout << "***********  5.����ְ����Ϣ ***********" << endl;
	cout << "***********  6.���ձ����Ϣ ***********" << endl;
	cout << "***********  7.��������ĵ� ***********" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}
void WorkerManager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
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
	//��һ��ʹ�ã��ļ�δ�������ļ����ڣ��������ݱ���գ��ļ����ڣ��ұ���������

}
void WorkerManager::Add_emp()
{
	cout << "��������Ҫ��ӵ�ְԱ��������" << endl;
	int addnum;//������������
	cin >> addnum;
	if (addnum < 0)
	{
		cout << "��������ȷ������" << endl;
	}
	else {
		for (int ii = 0; ii < addnum; ii++)
		{
			int id;
			string name;
			int did;
			while (true)
			{
				cout << "�������" << ii + 1 << "��Ա���ı��" << endl;
				cin >> id;
				cout << endl;
				if (isexit(id)==-1)
					break;
				cout << "id�ظ���" << endl;
			}
			cout << "�������" << ii + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "�������" << ii + 1 << "��Ա���Ĳ���" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "��ӳɹ�" << endl;
		}
		WorkerManager::mem_save();
	}
	//�����������
	system("pause");
	system("cls");
}
int WorkerManager::get_empmem()//ͳ���ļ��е�����
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;//ͳ������
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
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	else if (this->m_num == 0)
		cout << "��ʱ����Ϊ0" << endl;
	else
	{
		for (int ii = 0; ii < m_num; ii++)
		{
			//���ö�̬���ó���ӿ�
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
	cout << "������ɾ����id" << endl;
	cin >> id;
	if (isexit(id) == -1)
	{
		cout << "�����id������" << endl;
	}
	else{
		this->m_arr.erase(m_arr.begin() + isexit(id) - 1);
		this->m_num--;

		cout << "ɾ���ɹ�" << endl;
	}
	this->mem_save();
	system("pause");
	system("cls");
}
void WorkerManager::change_emp()
{
	int id;
	cout << "������Ҫ�޸�Ա���ı�ţ� ";
	cin >> id;
	int ii = isexit(id);
	if (ii == -1)
		cout << "�˱�ŵ�Ա��������!" << endl;
	else {
		this->m_arr[ii]->showinfo();
		int id_;
		string name;
		int did;
		while (true) {
			cout << "�������Ա�����±�ţ� ";
			cin >> id_;
			cout << endl;
			if (isexit(id_)==-1||id_==id)
				break;
			else
			{
				cout << "����ظ���" << endl;
			}
		}
		cout << "�������Ա���������� ";
		cin >> name;
		cout << endl;
		cout << "�������Ա���Ĳ��ű�ţ� "<<endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> did;
		m_arr[ii]->m_Id = id_;
		m_arr[ii]->m_Name = name;
		m_arr[ii]->m_DeptId = did;
		cout << "�޸ĳɹ�" << endl;
		this->mem_save();
		system("pause");
		system("cls");
	}
}
