/*
 * Student.cpp
 * I pledge my Honor that I have abided by the Stevens Honor System
 *  Created on: Sep 7, 2017
 *      Author: alexanderlu
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
 * Main class includes the private variables first name, last name, gpa, id. Public methods include returning the full name
 * id, gpa, and printing all the information about the student
 */
class student{
public:
	student(string first, string last, float gpa, int id) : first_{first}, last_{last}, gpa_{gpa}, id_{id} { }

	string full_name() const{
		return first_ + " " + last_;
	}

	int id() const{
		return id_;
	}
	 float gpa() const
	 {
		 return gpa_;
	 }
	 void print_info() const{
		 cout<< full_name() << ", GPA: " << setprecision (2) << fixed << gpa() << ", ID: " << id() << endl;
	 }
	 // print_info() should print in the format (GPA has 2 decimal places):
	 // Bob Smith, GPA: 3.50, ID: 20146

private:
	string first_, last_;
	float gpa_;
	int id_;

};


/**
* Takes a vector of Student objects, and returns a new vector
* with all Students whose GPA is < 1.0.
*/

vector<student> find_failing_students(const vector<student> &students) {
	vector<student> failing_students;
	for(const auto &s: students)
	{
		if (s.gpa() < 1.0)
			failing_students.push_back(s);
	}
	return failing_students;
}

/**
* Prints the list of students given a vector
*/
void print_students(const vector<student> &students) {
	for(const auto &s: students){
		s.print_info();
	}

}


/**
* Allows the user to enter information for multiple students, then
* find those students whose GPA is below 1.0 and prints them to the
* screen.
*/
int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<student> students;
	do
	{
		cout<< "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while (gpa < 0 || gpa > 4){
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	}
	while (repeat == 'Y' || repeat == 'y');
	cout << endl << "All students:" << endl;
	print_students(students);
	cout << endl << "Failing students:";
	if(find_failing_students(students).empty()==true)
	{
		cout << " None" << endl;
	}
	else
	{
		cout << "" << endl;
		print_students(find_failing_students(students));
	}
	return 0;
}
