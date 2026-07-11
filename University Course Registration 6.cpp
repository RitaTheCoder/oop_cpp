#include <iostream>
using namespace std;

class Course
{
public:
    string code, name;
    int credit;
    float grade;
};

class Student
{
public:
    int id;
    string name;
    Course c[6];
    int total = 0;

    void inputStudent()
    {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);
    }

    void registerCourse()
    {
        int n;
        cout << "How many courses (Maximum 6): ";
        cin >> n;

        if(n > 6)
            n = 6;

        for(int i = 0; i < n; i++)
        {
            string code;

            cout << "\nCourse " << i + 1 << endl;
            cout << "Course Code: ";
            cin >> code;

            bool duplicate = false;

            for(int j = 0; j < total; j++)
            {
                if(c[j].code == code)
                {
                    duplicate = true;
                    break;
                }
            }

            if(duplicate)
            {
                cout << "Duplicate Course! Registration Cancelled.\n";
                i--;
                continue;
            }

            c[total].code = code;

            cin.ignore();

            cout << "Course Name: ";
            getline(cin, c[total].name);

            cout << "Credit Hour: ";
            cin >> c[total].credit;

            cout << "Grade Point: ";
            cin >> c[total].grade;

            total++;
        }
    }

    void dropCourse()
    {
        string code;

        cout << "\nEnter Course Code to Drop: ";
        cin >> code;

        for(int i = 0; i < total; i++)
        {
            if(c[i].code == code)
            {
                for(int j = i; j < total - 1; j++)
                    c[j] = c[j + 1];

                total--;
                cout << "Course Dropped Successfully.\n";
                return;
            }
        }

        cout << "Course Not Found.\n";
    }

    void result()
    {
        int totalCredit = 0;
        float totalPoint = 0;

        cout << "\nRegistered Courses\n";

        for(int i = 0; i < total; i++)
        {
            cout << c[i].code << " "
                 << c[i].name << " "
                 << c[i].credit << " Credit "
                 << "GP: " << c[i].grade << endl;

            totalCredit += c[i].credit;
            totalPoint += c[i].credit * c[i].grade;
        }

        cout << "\nTotal Credit Hours = " << totalCredit;

        if(totalCredit > 0)
            cout << "\nSemester GPA = " << totalPoint / totalCredit;
        else
            cout << "\nSemester GPA = 0";
    }
};

int main()
{
    Student s;

    s.inputStudent();

    s.registerCourse();

    s.dropCourse();

    s.result();

    return 0;
}
