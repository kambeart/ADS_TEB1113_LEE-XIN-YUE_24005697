#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string course;
    int age;
};

int main() {

    Student student[5];

    student[0].id = "24007271";
    student[0].name = "Reeyan";
    student[0].course = "IT";
    student[0].age = 25;

    student[1].id = "24006463";
    student[1].name = "Ananda";
    student[1].course = "CS";
    student[1].age = 18;

    student[2].id = "24005697";
    student[2].name = "Xin";
    student[2].course = "CS";
    student[2].age = 20;

    student[3].id = "24009999";
    student[3].name = "pippipi";
    student[3].course = "BM";
    student[3].age = 999;

    student[4].id = "25002829";
    student[4].name = "hihi";
    student[4].course = "PE";
    student[4].age = 21;

    // Display all records
    cout << "Student Records:\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Course: " << student[i].course << endl;
        cout << "Age: " << student[i].age << endl;
        cout << endl;
    }

    // Search student by ID
    string identered;
    cout << "Input Student ID to search: ";
    cin >> identered;

    bool foundSearch = false;

    for (int i = 0; i < 5; i++) {
        if (student[i].id == identered) {
            foundSearch = true;

            cout << "\nStudent Found:\n";
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "Course: " << student[i].course << endl;
            cout << "Age: " << student[i].age << endl;

            break;
        }
    }

    if (!foundSearch) {
        cout << "Student ID not found." << endl;
    }

    // Update student record
    string updateID;
    cout << "\nEnter Student ID to update: ";
    cin >> updateID;

    bool foundUpdate = false;

    for (int i = 0; i < 5; i++) {
        if (student[i].id == updateID) {
            foundUpdate = true;

            cout << "\nCurrent Record:\n";
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "Course: " << student[i].course << endl;
            cout << "Age: " << student[i].age << endl;

            cout << "\nEnter new name: ";
            cin >> student[i].name;

            cout << "Enter new course: ";
            cin >> student[i].course;

            cout << "Enter new age: ";
            cin >> student[i].age;

            cout << "\nRecord Updated Successfully!\n";

            cout << "\nUpdated Record:\n";
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "Course: " << student[i].course << endl;
            cout << "Age: " << student[i].age << endl;

            break;
        }
    }

    if (!foundUpdate) {
        cout << "Student ID not found." << endl;
    }

    return 0;
}