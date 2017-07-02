#pragma once
#ifndef CLASS_HEADER_H
#define CLASS_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
struct Course
{
	string department;
	int number;
	int credit_hours;
};
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
		max_courses = 3;
		p_courses = nullptr;
	}
	Student(const Student &student_copy)
	{
		first_name = student_copy.first_name;
		last_name = student_copy.last_name;
		ID = student_copy.ID;
		num_courses = student_copy.num_courses;
		max_courses = student_copy.max_courses;
		delete[] p_courses;
		p_courses = new Course[num_courses];
		for (int a = 0; a < num_courses; a++)
		{
			p_courses[a] = student_copy.p_courses[a];
		}
	}
	~Student()
	{
		delete[] p_courses;
		p_courses = nullptr;
	}
	Student& operator = (const Student& rhs)
	{
		first_name = rhs.first_name;
		last_name = rhs.last_name;
		ID = rhs.ID;
		num_courses = rhs.num_courses;
		max_courses = rhs.max_courses;
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
	int add_course(const Course& a, int num_courses);
	bool remove_course(const Course& a, int num_courses);
	bool is_enrolled(const Course& aCourse) const;
	bool read_data(istream& in);
	bool write_data(ostream& out);
	double tuition_due() const;
	friend istream& operator >> (istream& in, Student& data);
	friend ostream& operator << (ostream& out, const Student& data);
};
istream& operator >> (istream& in, Student& data)
{
	in >> data.ID >> data.first_name >> data.last_name;
	return in;
}
istream& operator >> (istream& in, Course& data)
{
	in >> data.department >> data.number >> data.credit_hours;
	return in;
}
ostream& operator << (ostream& out, const Student& data)
{
	out << data.ID << data.first_name << data.last_name;
	return out;
}
ostream& operator << (ostream& out, const Course& data)
{
	out << data.department << " " << data.number << " " << data.credit_hours << endl;
	return out;
}

int Student::add_course(const Course& a, int num_courses)
{
	if (p_courses=nullptr)
		p_courses = new Course[max_courses];//here we are assuming our drop out rate is very high
	if (num_courses >= max_courses)
	{
		Course *r;
		num_courses = num_courses * 2 + 1;
		r = new Course[num_courses];
		for (int j = 0; j < num_courses; j++)
		{
			r[j] = p_courses[j];
		}
		if (p_courses != nullptr)
			delete[] p_courses;
		p_courses = r;
	}
	p_courses[num_courses] = a;
	num_courses++;
	return num_courses;
}
bool Student::remove_course(const Course& a, int num_courses)
{}
bool Student::is_enrolled(const Course& aCourse) const
{}
bool Student::read_data(istream& in)
{
	in >> ID >> first_name >> last_name >> num_courses;
	for (int i = 0; i < num_courses; i++)
	{
		add_course
	}
	if (first_name.isdigit() || last_name.isdigit())
		return false;
	else
		return true;

}
bool Student::write_data(ostream& out)
{
	out << ID << " " << first_name << " " << last_name << " " << num_courses;

}
double Student::tuition_due() const
{
	float total=0;
	float grand_total = 10;//library fee
	float pastry_fund = 0;
	total += 476 * a.credit_hours;
	total += 0.75 * a.credit_hours;
	if (a.department == "CS" || a.department == "IT" || a.department == "ECE" || a.department == "CE" || a.department == "ME")
		total += 15 * a.credit_hours;//lab expenses
	grand_total += total;
	pastry_fund = grand_total*0.0025;
	grand_total += pastry_fund;
	return total;
}

#endif
