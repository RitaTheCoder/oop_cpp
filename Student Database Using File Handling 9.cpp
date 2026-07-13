#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Student
{
public:
    int id;
    char name[50];
    char department[50];
    float cgpa;

    void input()
    {
        cout << "Enter Student ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Department: ";
        cin.getline(department, 50);

        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void display()
    {
        cout << "-----------------------------\n";
        cout << "ID         : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "CGPA       : " << cgpa << endl;
    }
};

void addStudent()
{
    Student s;

    ofstream file("students.dat", ios::binary | ios::app);

    s.input();

    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "Student Added Successfully.\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s, sizeof(s)))
    {
        s.display();
    }

    file.close();
}

void searchStudent()
{
    Student s;
    int id;
    bool found = false;

    cout << "Enter Student ID: ";
    cin >> id;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.id == id)
        {
            s.display();
            found = true;
            break;
        }
    }

    file.close();

    if(!found)
        cout << "Student Not Found.\n";
}

void updateStudent()
{
    Student s;
    int id;
    bool found = false;

    cout << "Enter Student ID: ";
    cin >> id;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.id == id)
        {
            cout << "Enter New Information\n";

            cin.ignore();

            cout << "Name: ";
            cin.getline(s.name,50);

            cout << "Department: ";
            cin.getline(s.department,50);

            cout << "CGPA: ";
            cin >> s.cgpa;

            file.seekp(-sizeof(s), ios::cur);

            file.write((char*)&s, sizeof(s));

            found = true;

            cout << "Record Updated.\n";

            break;
        }
    }

    file.close();

    if(!found)
        cout << "Student Not Found.\n";
}

void deleteStudent()
{
    Student s;
    int id;
    bool found = false;

    cout << "Enter Student ID: ";
    cin >> id;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.id == id)
        {
            found = true;
        }
        else
        {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat","students.dat");

    if(found)
        cout << "Student Deleted Successfully.\n";
    else
        cout << "Student Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Database =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "Program End.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    }while(choice != 6);

    return 0;
}
