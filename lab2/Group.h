#pragma once
#include <vector>
#include "Session_schedule.h"
#include "Department.h"

using namespace std;
class Group { // группа
private:
	int num_group;
	vector<Student> students;
	Session_schedule schedule;
	vector<Educator> educators;
public:
	int Get_count_of_student() {
		return students.size();
	}

	Group(int num_group, vector<Student> students, Session_schedule schedule) {
		for (int i = 0; i < students.size(); i++) {
			this->students.push_back(students[i]);
		}
		this->num_group = num_group;
		this->schedule = schedule;
	}

	void Add_Department_Educator(Department& department) {
		for (int i = 0; i < department.Get_Count_Educator(); i++) {
			for (int j = 0; j < schedule.Size(); j++) {
				if (schedule.Get_Subject(j) == department.Get_Educator(i).get_subject()) {
					educators.push_back(department.Get_Educator(i));
					schedule.Del_Subject(j);
				}
			}
		}
	}

	void Pass_The_Exams() {
		for (int i = 0; i < educators.size(); i++) {
			for (int j = 0; j < students.size(); j++) {
				students[j].set_mark(educators[i].give_mark(3 + rand() % 8, students[j].Get_Fio()));
			}
		}
	}

	void Del_Stud(int index) {
		students.erase(students.begin() + index);
	}

	Student Get_Student(int index) {
		return students[index];
	}

	void SetSesSchedule(Session_schedule& schedule) {
		this->schedule = schedule;
	}

	Subject Get_Subject(int index) {
		return schedule.Get_Subject(index);
	}
};