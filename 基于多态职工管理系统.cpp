#include<iostream>
#include<string>
#include"workerManage.h"
#include<vector>

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

int main()
{
	//ʵ�����������
	WorkerManager wm;
	int choice = 0;
	while (true)
	{

		wm.show_menu();
		cout << "����������ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exit_system();
			break;
		case 1://����ְ��,�ڳ�����ά������������ȵ����飬���Խ����鴴���ڶ�����������worker** ��ָ��ά��,Ҳ������vector
			wm.Add_emp();
			break;
		case 2://��ʾְ��
			wm.show_emp();
			break;
		case 3://ɾ��ְ��
			wm.del_emp();
			break;
		case 4://�޸�ְ��
			wm.change_emp();
			break;
		case 5://����ְ��
			break;
		case 6://���ձ������
			break;
		case 7://��������ĵ�
			break;
		default:
			system("cls");
			break;
		}
	}
	wm.show_menu();
	system("pause");
	return 0;
}