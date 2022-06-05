#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Team {
public:
	Manager manager;
	vector <Worker> workers;
	
	Team(int i){
		manager.setName(to_string(i));
	}
	void setWork(int n) {
		srand(n);
		int tmp = (rand() % (workers.size()-manager.questcount) + 1);
		tmp += manager.questcount;
		for (int i = manager.questcount; i < tmp; i++) {
			workers[i].setWork();
			int r = rand() % 3;
			switch (r)
			{
			case 0:
				workers[i].setType(A);
				break;
			case 1:
				workers[i].setType(B);
				break;
			case 2:
				workers[i].setType(C);
				break;
			}
		}
		manager.questcount = tmp;
	}
	bool full() {
		if (manager.questcount == workers.size()) {
			return true;
		}
		return false;
	}

};
class Company
{
	Head head;
	vector <Team> teams;
public:
	void start() {
		cout << "Entre count of teams and worker in it\n";
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < x; i++) {
			teams.emplace_back(i);
			for (int j = 0; j < y; j++) {
				teams[i].workers.emplace_back(to_string(i)  + to_string(j));
			}
		}
		while (true) {
			int n = head.setQuest();
			int tmp = 0;
			for (int i = 0; i < teams.size(); i++) {
				if (!teams[i].full()) {
					teams[i].setWork(n + i);
					tmp++;
				}
				
			}
			if (tmp == 0) {
				break;
			}

		}
		cout << "All teams are full of quests\n";
	}

};

