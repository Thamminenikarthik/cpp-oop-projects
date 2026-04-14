#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int marks;
    char grade;

public:
    Student(int i = 0, string n = "", int m = 0);

    int getId();
    void display();

    void update(int newMarks);
    char calculateGrade(int marks);

    string serialize();
    void deserialize(string data);
};

#endif