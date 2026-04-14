#include "StudentSystem.h"
#include <iostream>
using namespace std;

int main() {
    StudentSystem sys;
    sys.loadFromFile();

    int choice;

    do {
        cout << "\n1.Add 2.Delete 3.Update 4.View 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sys.addStudent(); break;
            case 2: sys.deleteStudent(); break;
            case 3: sys.updateStudent(); break;
            case 4: sys.viewAll(); break;
            case 5: sys.saveToFile(); break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}