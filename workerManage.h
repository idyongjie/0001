#pragma once //��֤ͷ�ļ�ֻ������һ��
#include<iostream>//���������ͷ�ļ�
#include<string>
#include<vector>
#include<fstream>

#define FILENAME "empfile.txt"

#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"

using namespace std;//��׼�����ռ�
class WorkerManager
{
public:
	WorkerManager();
	void show_menu();//չʾ�˵� �� .h�ļ�ֻ������
	void exit_system();
	void Add_emp();
	int get_empmem();
	void init_emp();
	void show_emp();
	int isexit(int id);//�ж�ĳid�Ƿ���ڣ������򷵻�id���������򷵻�-1
	void del_emp();
	void change_emp();

	void mem_save();
	void men_read();

	vector<worker*>m_arr;
	int m_num;
	bool m_fileisempty;       //�ж��ļ��Ƿ����
	
	~WorkerManager();
};
