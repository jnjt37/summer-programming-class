/*
Name: Jaxson Johnston
Assignment: Project 4
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "class_header.h"

using namespace std;

int main()
{
	Student *students;
	Course course_list[100];
	int num_students = 0;
	int different_courses = 0;
	int enrollment_size = 5;
	students = new Student[enrollment_size];
	ifstream student_file;
	student_file.open("students.txt");
	while (!student_file.eof())
	{
		if (num_students == enrollment_size)
		{
			Student *q;
			enrollment_size = enrollment_size * 2 + 5;
			q = new Student[enrollment_size];
			for (int j = 0; j < num_students; j ++)
			{
				q[j] = students[j];
			}
			if (students != nullptr)
				delete[] students;
			students = q;
		}
		student_file >> students[num_students];
		num_students++;
	}
	student_file.close();
	ifstream schedules_file;
	schedules_file.open("schedules.txt");
	while (!schedules_file.eof())
	{
		int temp_ID;
		int student_ID;
		bool exists = false;
		Course course_temp;
		schedules_file >> course_temp;
		if (different_courses == 0)
		{
			copy_course(course_list[0],course_temp);
			different_courses++;
		}
		for (int m = 0; m < different_courses; m++)
		{
			if (course_list[m] == course_temp)
				exists = true;
		}
		if (exists == false)
		{
			copy_course(course_list[different_courses], course_temp);
			different_courses++;
		}
		schedules_file >> temp_ID;
		for (int i = 0; i < num_students; i++)
		{
			student_ID = students[i].get_ID();
			if (temp_ID == student_ID)
			{
				students[i].add_course(course_temp);
			}
		}
	}
	schedules_file.close();
	ofstream student_schedules;
	student_schedules.open("studentSchedules.txt");
	for (int k = 0; k < enrollment_size; k++)
	{
		cout << students[k];
		int temp_num_courses=0;
		temp_num_courses = students[k].get_num_courses();
		students[k].write_data();
		cout<<"$"<<fixed<<setprecision(2)<<students[k].tuition_due()<<endl;
	}
	student_schedules.close();
	ofstream enrolled_students;
	enrolled_students.open("courseEnrollments.txt");
	for (int r = 0; r < 100; r++)
	{
		cout << course_list[r];
		if (students[r].course_check(course_list[r]) == true)
			cout << students[r];
	}
	enrolled_students.close();
    return 0;
}