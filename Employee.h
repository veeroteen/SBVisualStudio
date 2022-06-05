#pragma once
#include <string>
#include <iostream>
#include <random>
using namespace std;
enum Type {
	A,
	B,
	C
};

class Employee
{
	string name;
public:
	string getName() {
		return name;
	}
	void setName(string str) {
		name = str;
	}
};

class Head :public Employee {
	int quest;
public:
	int setQuest() 
	{
		cout << "Enter quest\n";
		cin >> quest;
		return quest;
	}
	int getQuest() 
	{
		return quest;
	}
};

class Manager :public Employee {
public:
	int questcount = 0;
};

class Worker :public Employee {
	bool work = false;
	Type type; 
public:
	Worker(string i) {
		setName(i);
	}
	void setWork() {
		work = true;
	}
	void setType(Type t) {
		type = t;
	}
	bool getWork() {
		return work;
	}
};