#pragma once //保证头文件只被编译一次
#include<iostream>//输入输出流头文件
#include<string>
using namespace std;
class worker
{
public:
	virtual void showinfo() = 0;
	virtual string getDeptName() = 0;
	int m_Id;
	string m_Name;
	int m_DeptId;
};