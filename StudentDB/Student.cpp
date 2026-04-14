#include "Student.h"
#include <iostream>
#include <sstream>   
using namespace std;

Student::Student(int i, string n, int m) {
    id = i;
    name = n;
    marks = m;
    grade = calculateGrade(marks);
}

int Student::getId() {
    return id;
}

char Student::calculateGrade(int m) {
    if (m >= 90) return 'A';
    else if (m >= 75) return 'B';
    else if (m >= 50) return 'C';
    else return 'F';
}

void Student::update(int newMarks) {
    marks = newMarks;
    grade = calculateGrade(marks);
}

void Student::display() {
    cout << "ID: " << id
         << " Name: " << name
         << " Marks: " << marks
         << " Grade: " << grade << endl;
}

string Student::serialize() {
    // ⚠️ using space assumes name has no spaces
    return to_string(id) + " " + name + " " +
           to_string(marks) + " " + grade;
}

void Student::deserialize(string data) {
    stringstream ss(data);

  
    ss >> id >> name >> marks >> grade;
}