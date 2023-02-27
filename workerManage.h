#pragma once //保证头文件只被编译一次
#include<iostream>//输入输出流头文件
#include<string>
#include<vector>
#include<fstream>

#define FILENAME "empfile.txt"

#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"

using namespace std;//标准命名空间
class WorkerManager
{
public:
	WorkerManager();
	void show_menu();//展示菜单 ， .h文件只做声明
	void exit_system();
	void Add_emp();
	int get_empmem();
	void init_emp();
	void show_emp();
	int isexit(int id);//判断某id是否存在，存在则返回id，不存在则返回-1
	void del_emp();
	void change_emp();

	void mem_save();
	void men_read();

	vector<worker*>m_arr;
	int m_num;
	bool m_fileisempty;       //判断文件是否存在
	
	~WorkerManager();
};
