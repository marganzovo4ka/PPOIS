#pragma once
#include "Student.h"
#include "Group.h"
class Decan : public Person { // декан
public:
	void expulsion_of_student(Student student, Group group){
		for (int i = 0; i < group.Get_count_of_student(); i++) {
			if (student == group.Get_Student(i))
				group.Del_Stud(i);
		}
	}
};