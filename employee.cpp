#include"employee.h"

employee::employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void employee:: showinfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ�������� " << this->m_Name
		<< "\tְ����λ�� " << this->getDeptName()
		<<"\t��λְ����ɾ��������"<<endl;
}
string employee::getDeptName()
{
	return string("Ա��");
}
