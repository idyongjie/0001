#pragma once //��֤ͷ�ļ�ֻ������һ��
#include<iostream>//���������ͷ�ļ�
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