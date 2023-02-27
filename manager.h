#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;

class manager :public worker
{
public:
	manager(int id, string name, int did);
	virtual void showinfo();
	virtual string getDeptName();
};