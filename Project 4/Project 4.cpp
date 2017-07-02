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
	int num_students = 0;
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
		cin >> students[num_students];
		num_students++;
	}
	student_file.close();
	ifstream schedules_file;
	schedules_file.open("schedules.txt");
	while (!schedules_file.eof())
	{
		int temp_ID;
		int student_ID;
		Course course_temp;
		cin >> course_temp;
		cin >> temp_ID;
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
		for (int l = 0; l < temp_num_courses; l++)
		{
			cout<<students[k].write_data(students[k])<<endl;
		}
		cout<<"$"<<fixed<<setprecision(2)<<students[k].tuition_due()<<endl;
	}
	student_schedules.close();
	ofstream enrolled_students;
	enrolled_students.open("courseEnrollments.txt");
	
	enrolled_students.close();
    return 0;
}

