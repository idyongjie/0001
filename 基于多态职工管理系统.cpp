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
	//实例化管理对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{

		wm.show_menu();
		cout << "请输入您的选择: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exit_system();
			break;
		case 1://增加职工,在程序中维护这个不定长度的数组，可以将数组创建在堆区，并利用worker** 的指针维护,也可以用vector
			wm.Add_emp();
			break;
		case 2://显示职工
			wm.show_emp();
			break;
		case 3://删除职工
			wm.del_emp();
			break;
		case 4://修改职工
			wm.change_emp();
			break;
		case 5://查找职工
			break;
		case 6://按照编号排序
			break;
		case 7://清空所有文档
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