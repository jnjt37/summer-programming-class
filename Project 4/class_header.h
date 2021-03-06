#pragma once
#ifndef CLASS_HEADER_H
#define CLASS_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct Course
{
	string department;
	int number;
	int credit_hours;
};
bool operator == (const Course& lhs, const Course& rhs)
{
	return((lhs.department == rhs.department) && (lhs.number == rhs.number) && (lhs.credit_hours == rhs.credit_hours));
}
class Student
{
private:
	string first_name, last_name;		
	int ID,num_courses=0, max_courses = 3;;
	Course *p_courses;
public:
	//constructors, destructors, and assignment operator
	Student()
	{
		string first_name = "";
		string last_name = "";
		int ID = 0;
		int num_courses = 0;
		int max_courses = 3;
		p_courses = new Course[max_courses];
	}
	Student(const Student &student_copy)
	{
		first_name = student_copy.first_name;
		last_name = student_copy.last_name;
		ID = student_copy.ID;
		num_courses = student_copy.num_courses;
		max_courses = student_copy.max_courses;
		//delete[] p_courses;
		p_courses = new Course[num_courses];
		for (int a = 0; a < num_courses; a++)
		{
			p_courses[a] = student_copy.p_courses[a];
		}
	}
	~Student()
	{
		if (p_courses != nullptr)
		{
			delete[] p_courses;
			p_courses = nullptr;
		}
	}
	Student& operator = (const Student& rhs)
	{
		first_name = rhs.first_name;
		last_name = rhs.last_name;
		ID = rhs.ID;
		num_courses = rhs.num_courses;
		max_courses = rhs.max_courses;
		if(p_courses!=nullptr)
			delete[] p_courses;
		p_courses = new Course[num_courses];
		for (int a = 0; a < num_courses; a++)
		{
			p_courses[a] = rhs.p_courses[a];
		}
		return *this;
	}
	//getters
	int get_ID() const { return ID; };
	int get_num_courses() const { return num_courses; };
	string get_first_name() const { return first_name; };
	string get_last_name() const { return last_name; };
	//setters
	void set_ID(int id) { ID = id; };
	void set_first_name(string first) {first_name = first;};
	void set_last_name(string last) { last_name = last; };
	//additional functions
	int add_course(const Course& a);
	//bool remove_course(const Course& a);
	//bool is_enrolled(const Course& aCourse) const;
	//bool read_data(istream& in);
	void write_data();
	bool course_check(const Course a) 
	{
		for (int o = 0; o < num_courses; o++)
		{
			if (a == p_courses[o])
				return true;
		}
		return false;
	}
	double tuition_due() const;
	friend istream& operator >> (istream& in, Student& data);
	friend ostream& operator << (ostream& out, const Student& data);
};
istream& operator >> (istream& in, Student& data)
{
	in >> data.ID >> data.first_name >> data.last_name>>data.num_courses;
	return in;
}
istream& operator >> (istream& in, Course& data)
{
	in >> data.department >> data.number >> data.credit_hours;
	return in;
}
ostream& operator << (ostream& out, const Student& data)
{
	out << data.ID << data.first_name << data.last_name<<data.num_courses;
	return out;
}
ostream& operator << (ostream& out, const Course& data)
{
	out << data.department << " " << data.number << " " << data.credit_hours << endl;
	return out;
}
int Student::add_course(const Course& a)
{
	if (p_courses==nullptr)
		p_courses = new Course[max_courses];//here we are assuming our drop out rate is very high
	if (num_courses >= max_courses)
	{
		Course *r;
		num_courses = num_courses * 2 + 1;
		r = new Course[num_courses];
		for (int j = 0; j < num_courses; j++)
		{
			r[j]=p_courses[j];
		}
		if (p_courses != nullptr)
			delete[] p_courses;
		p_courses = r;
	}
	p_courses[num_courses]=a;
	num_courses++;
	return num_courses;
}
/*
bool Student::remove_course(const Course& a)
{}
bool Student::is_enrolled(const Course& aCourse) const
{}
bool Student::read_data(istream& in)
{}
*/
void Student::write_data()
{
	for (int m = 0; m < num_courses; m++)
	{
		cout << p_courses[m]<<endl;
	}
	return;
}
double Student::tuition_due() const
{
	float total=0;
	float grand_total = 10;//library fee
	float pastry_fund = 0;
	for (int l = 0; l < num_courses; l++)
	{
		total += 476 * p_courses[l].credit_hours;
		total += 0.75 * p_courses[l].credit_hours;
		if (p_courses[l].department == "CS" || p_courses[l].department == "IT" || p_courses[l].department == "ECE" || p_courses[l].department == "CE" || p_courses[l].department == "ME")
			total += 15 * p_courses[l].credit_hours;//lab expenses
	}
	grand_total += total;
	pastry_fund = grand_total*0.0025;
	grand_total += pastry_fund;
	return grand_total;
}
#endif
