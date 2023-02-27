#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;

class boss :public worker
{
public:
	boss(int id, string name, int did);
	virtual void showinfo();
	virtual string getDeptName();
};