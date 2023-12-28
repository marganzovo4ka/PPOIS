#pragma once
#include "Person.h"
#include "Session_schedule.h"
#include "Subject.h"

class Zam_Decana : public Person { // чувак который делает расписание
private:
	int count_of_exam = 5;
public:
	void Set_Count_Of_Exam(int count) {
		this->count_of_exam = count;
	}
	Session_schedule Create_Schedule(vector<Subject> exam_subject) {
		Session_schedule schedule;
		for (int i = 0; i < count_of_exam; i++) {
			schedule.AddSubjectToExam(exam_subject[i]);
		}
		return schedule;
	}
};