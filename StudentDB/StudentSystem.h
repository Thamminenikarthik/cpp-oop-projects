#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include "Student.h"
#include <vector>
using namespace std;

class StudentSystem {
private:
    vector<Student> students;

public:
    void addStudent();
    void deleteStudent();
    void updateStudent();
    void viewAll();

    Student* findStudent(int id);

    void saveToFile();
    void loadFromFile();
};

#endif