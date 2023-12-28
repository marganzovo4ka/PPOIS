#pragma once
#include <string>
using namespace std;

class Person {
protected:
	string fio;

public:
	string Get_Fio() {
		return this->fio;
	}

	void Set_Fio(string fio) {
		this->fio = fio;
	}
};