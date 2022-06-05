#pragma once
#include <string>
#include <random>
#include <vector>
#include <iostream>
using namespace std;
class Branch
{
public:
	Branch* parent;
	vector <Branch> childrens;
	string elfName;

	Branch(Branch* parent) {

		this->parent = parent;
	}
	Branch() {

		parent = nullptr;
		int count = 2 + (rand() % 2);
		for (int i = 0; i < count; i++) {
			childrens.emplace_back(this);
		}
		
	}
	
	Branch* getParent() {
		return parent;
	}

	Branch* getChild() {
		return &childrens[0];
	}

	string getName() {
		return elfName;
	}

	Branch* getBranch() {
		return this;
	}


	void setName() {
		cout << "Enter elf name\n";
		cin >> elfName;
		if (parent == nullptr) {
			for (int i = 0; i < childrens.size(); i++) {
				childrens[i].setName();
			}
		}

	}

	int findName(string name) {
		if (elfName == name) {
			return count();
		}
		for (int i = 0; i < childrens.size(); i++) {
			if (childrens[i].elfName == name) {
				return childrens[i].count();
			}
		}
		return 0;

	}

	int count() {
		if (parent != nullptr) {
			return parent->count();
		}
		int count = 0;
		if (elfName != "None")
		{
			count++;
		}
		for (int i = 0; i < childrens.size(); i++) {
			if (elfName != "None")
			{
				count++;
			}
		}
		return count;
	}


};

