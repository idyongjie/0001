#include"manager.h"
manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void manager::showinfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ�������� " << this->m_Name
		<< "\tְ����λ�� " << this->getDeptName()
		<< "\t��λְ������ϰ�����񣬽���Ա������" << endl;
}
string manager::getDeptName()
{
	return string("����");
}