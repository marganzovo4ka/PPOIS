#pragma once
#include <vector>
#include <string>
#include "Subject.h"
using namespace std;

class Session_schedule {
private:
	vector<Subject> exam_shedule;
public:
	void AddSubjectToExam(Subject subject) {
		exam_shedule.push_back(subject);
	}
	Session_schedule& operator= (Session_schedule& schedule) {
		for (int i = 0; i < schedule.exam_shedule.size(); i++)
			this->exam_shedule.push_back(schedule.exam_shedule[i]);
		return *this;
	}
	Subject Get_Subject(int index) {
		return exam_shedule[index];
	}

	int Size() {
		return exam_shedule.size();
	}

	void Del_Subject(int index) {
		exam_shedule.erase(exam_shedule.begin() + index);
	}
};