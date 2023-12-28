#pragma once
#include "Student.h"
#include "Subject.h"

using namespace std;
	class Educator : public Person {
private:
	Subject subject;
public:

	Educator(Subject subject) {
		this->subject = subject;
	}
	Mark give_mark(int value, string fio) {
		Mark mark(value, subject, fio);
		return mark;
	} 
	Subject get_subject() {
		return this->subject;
	}
};