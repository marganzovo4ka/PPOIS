#pragma once
#include"Person.h"
#include"Mark.h"
#include <vector>
using namespace std;

class Student : public Person {
protected:
	vector<Mark> marks;
public:
	Student() {}
	Student(string fio) {
		this->fio = fio;
	}
	int Get_count_of_marks() {
		return marks.size();
	} 
	void set_mark(Mark mark) {
		this->marks.push_back(mark);
	}
	Mark get_mark_i(int index) {
		return marks[index];
	}

	bool operator == (Student student) {
		if (this->fio == student.fio)
			return true;
		else return false;
	}

};