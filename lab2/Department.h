#pragma once
#include "Educator.h"
class Department {
private:
	string name;
	vector<Educator> educators;
	int count_educator;
public:
	Department(string name, vector<Educator> educators) {
		this->name = name;
		for (int i = 0; i < educators.size(); i++)
			this->educators.push_back(educators[i]);
	}
	Educator Get_Educator(int index) {
		return educators[index];
	}
	void Add_Educator(Educator educator) {
		educators.push_back(educator);
	}

	int Get_Count_Educator() {
		this->count_educator = educators.size();
		return this->count_educator;
	}

};