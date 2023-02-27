#include"employee.h"

employee::employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void employee:: showinfo()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_Name
		<< "\t职工岗位： " << this->getDeptName()
		<<"\t岗位职责：完成经理的任务"<<endl;
}
string employee::getDeptName()
{
	return string("员工");
}
