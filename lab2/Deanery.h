#pragma once
#include <iostream>
#include "Department.h"
#include <vector>
#include "Decan.h"
#include "Zam_Decana.h"
#include "Group.h"

using namespace std;
class Deanery { // деканат
private:
	string faculty;
	vector<Department> departments;
	Decan decan;
	Zam_Decana zam_decana;
	vector<Group> groups;
public:
	Deanery(Decan decan, vector<Department> departments, string faculty, Zam_Decana zam_decana, vector<Group> groups) {
		this->faculty = faculty;
		this->decan = decan;
		this->zam_decana = zam_decana;
		for (int i = 0; i < departments.size(); i++) {
			this->departments.push_back(departments[i]);
		}
		for (int i = 0; i < groups.size(); i++) {
			this->groups.push_back(groups[i]);
		}
	}

	void Conduct_The_Exams(Group& group) {
			group.Pass_The_Exams();
	}

	void Analysis_Marks(Group& group) {
		for (int i = 0; i < group.Get_count_of_student(); i++) {
			int count_neud = 0;
			for (int j = 0; j < group.Get_Student(i).Get_count_of_marks(); j++) {
				if (group.Get_Student(i).get_mark_i(j).Get_Value() < 4) 
					count_neud++;
			}
			if (count_neud >= 2) {
				decan.expulsion_of_student(group.Get_Student(i), group);
			}
		}
	}
};