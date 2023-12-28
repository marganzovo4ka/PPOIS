#pragma once
#include "Subject.h"

class Mark {
private:
	Subject subject;
	int value;
	string student_name;
public:
	Mark(int value, Subject subject, string student_name) {
		this->value = value;
		this->subject = subject;
		this->student_name = student_name;
	}

	int Get_Value() {
		return value;
	}

	bool operator ==(int value) {
		if (this->value == value)
			return true;
		else return false;
	}
};