#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/All_Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Educator educator1(Subject::Math);
			educator1.Set_Fio("Natalia");
			Educator educator2(Subject::Phisics);
			educator2.Set_Fio("Sergey");
			vector<Educator> educators;
			educators.push_back(educator1);
			educators.push_back(educator2);
			Department department("Math_Department", educators);
			Assert::IsTrue(department.Get_Educator(0).Get_Fio() == "Natalia");
			Assert::AreEqual(department.Get_Count_Educator(), 2);
			Assert::IsTrue(department.Get_Educator(0).get_subject() == Subject::Math);
		}
		TEST_METHOD(TestMethod2)
		{
			Educator educator(Subject::Math);
			Session_schedule schedule;
			vector<Subject> subjects = { Subject::Chemistry, Subject::Math, Subject::Phisics, Subject::OOP, Subject::English };
			vector<Student> students;
			string names[5] = { "Anna", "Misha", "Sasha", "Katya", "Kolya" };
			for (int i = 0; i < 5; i++) {
				Student stud(names[i]);
				students.push_back(stud);
			}
			Zam_Decana zam_decana;
			zam_decana.Set_Fio("Vika");
			Group group(221702, students, zam_decana.Create_Schedule(subjects));
			Assert::IsTrue(group.Get_Subject(1) == Subject::Math);
			Assert::IsTrue(group.Get_Student(3).Get_Fio() == "Katya");
		}
		TEST_METHOD(TestMethod3)
		{
			Educator educator(Subject::Math);
			Session_schedule schedule;
			vector<Subject> subjects = { Subject::Chemistry, Subject::Math, Subject::Phisics, Subject::OOP, Subject::English };
			vector<Student> students;
			string names[5] = { "Anna", "Misha", "Sasha", "Katya", "Kolya" };
			for (int i = 0; i < 5; i++) {
				Student stud(names[i]);
				students.push_back(stud);
			}
			Zam_Decana zam_decana;
			for (int i = 0; i < students.size(); i++) {
				students[i].set_mark(educator.give_mark(i, students[i].Get_Fio()));
			}
			zam_decana.Set_Fio("Vika");
			Group group(221702, students, zam_decana.Create_Schedule(subjects));
			Assert::IsTrue(group.Get_Student(3).get_mark_i(0) == 3);
		}

		TEST_METHOD(TestMethod4)
		{
			Educator educator1(Subject::Math);
			educator1.Set_Fio("Alla");
			Educator educator2(Subject::Phisics);
			educator2.Set_Fio("Sergey");
			Educator educator3(Subject::PPOIS);
			educator2.Set_Fio("Michail");
			Educator educator4(Subject::OTS);
			educator2.Set_Fio("Natalia");
			Educator educator5(Subject::MOIS);
			educator2.Set_Fio("Daniil");
			vector<Educator> educators;
			educators.push_back(educator1);
			educators.push_back(educator2);
			vector<Educator> educators1;
			educators1.push_back(educator3);
			educators1.push_back(educator4);
			educators1.push_back(educator5);
			Department department1("Math_Department", educators);
			Department department2("IIS", educators1);
			vector<Department> departments;
			departments.push_back(department1);
			departments.push_back(department2);
			Session_schedule schedule;
			vector<Subject> subjects = { Subject::PPOIS, Subject::Math, Subject::Phisics, Subject::OTS, Subject::MOIS };
			vector<Student> students;
			string names[5] = { "Anna", "Misha", "Sasha", "Katya", "Kolya" };
			for (int i = 0; i < 5; i++) {
				Student stud(names[i]);
				students.push_back(stud);
			}
			Zam_Decana zam_decana;
			zam_decana.Set_Fio("Vika");
			Group group(221702, students, zam_decana.Create_Schedule(subjects));
			group.Add_Department_Educator(department1);
			group.Add_Department_Educator(department2);
			vector<Group> groups;
			groups.push_back(group);
			Decan decan;
			decan.Set_Fio("Marchenko Katya");
			Deanery deanery(decan, departments, "FITU", zam_decana, groups);
			deanery.Conduct_The_Exams(group);
			deanery.Analysis_Marks(group);
			Assert::IsTrue(group.Get_Student(0).get_mark_i(0) == 4);
		}
	};
}
