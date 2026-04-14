#include "StudentSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

void StudentSystem::addStudent() {
    int id, marks;
    string name;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Marks: ";
    cin >> marks;

    students.push_back(Student(id, name, marks));
    cout << "Student added\n";
}

void StudentSystem::deleteStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Deleted\n";
            return;
        }
    }
    cout << "Not found\n";
}

Student* StudentSystem::findStudent(int id) {
    for (auto &s : students)
        if (s.getId() == id)
            return &s;
    return nullptr;
}

void StudentSystem::updateStudent() {
    int id, marks;
    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);

    if (s) {
        cout << "Enter new marks: ";
        cin >> marks;
        s->update(marks);
        cout << "Updated\n";
    } else {
        cout << "Not found\n";
    }
}

void StudentSystem::viewAll() {
    for (auto &s : students)
        s.display();
}

void StudentSystem::saveToFile() {
    ofstream file("students.txt");

    for (auto &s : students)
        file << s.serialize() << endl;

    file.close();
}

void StudentSystem::loadFromFile() {
    ifstream file("students.txt");
    string line;

    while (getline(file, line)) {
        Student s;
        s.deserialize(line);
        students.push_back(s);
    }

    file.close();
}