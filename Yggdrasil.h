#pragma once
#include <string>
#include "Branch.h"
#include <random>
#include <vector>
class Yggdrasil
{
public:
	vector <Branch*> branches;

	Yggdrasil() {
		int count = 3 + (rand() % 3);
		
		for (int i = 0; i < count; i++)
		{
			branches.push_back(new Branch);
		}
	}
	
	void SetName() {
		for(int i = 0; i < branches.size(); i++)
		{
			branches[i]->setName();
		}
	}

	void findElf() {
		cout << "Enter elf name you want to find\n";
		string str;
		cin >> str;
		int n = 0;
		for (int i = 0; i < branches.size(); i++) {
			n = branches[i]->findName(str);
			if (n > 0) {
				break;
			}
		}

		cout << "Have " << n-1 << " neighbors\n";


	}

};

