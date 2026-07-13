#include <bits/stdc++.h>

using namespace std;

class Course
{
public:
    int id;
    char name[50];
    int credit;
};

class Teacher
{
public:
    int id;
    char name[50];
    char department[50];
};

class Student
{
public:
    int id;
    char name[50];
    char department[50];

    Course courses[6];
    int totalCourse=0;

    float gpa=0;

    void calculateGPA()
    {
        if(totalCourse==0)
            gpa=0;
        else
        {
            float total=0;

            for(int i=0;i<totalCourse;i++)
                total+=4.0;

            gpa=total/totalCourse;
        }
    }

    void transcript()
    {
        cout<<"\n----- Transcript -----\n";
        cout<<"ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Department : "<<department<<endl;

        cout<<"Courses\n";

        for(int i=0;i<totalCourse;i++)
        {
            cout<<courses[i].name
                <<" Credit:"<<courses[i].credit<<endl;
        }

        cout<<"GPA : "<<gpa<<endl;
    }
};

class Department
{
public:
    char name[50];
    int studentCount=0;
    int teacherCount=0;

    void statistics()
    {
        cout<<"\nDepartment : "<<name<<endl;
        cout<<"Students : "<<studentCount<<endl;
        cout<<"Teachers : "<<teacherCount<<endl;
    }
};

class University
{
public:

    Student students[100];
    Teacher teachers[50];
    Course courses[50];
    Department departments[10];

    int studentCount=0;
    int teacherCount=0;
    int courseCount=0;
    int departmentCount=0;

    void addDepartment()
    {
        Department d;

        cout<<"Department Name : ";
        cin.ignore();
        cin.getline(d.name,50);

        departments[departmentCount++]=d;
    }

    void addTeacher()
    {
        Teacher t;

        cout<<"Teacher ID : ";
        cin>>t.id;

        cin.ignore();

        cout<<"Teacher Name : ";
        cin.getline(t.name,50);

        cout<<"Department : ";
        cin.getline(t.department,50);

        teachers[teacherCount++]=t;
    }

    void addCourse()
    {
        Course c;

        cout<<"Course ID : ";
        cin>>c.id;

        cin.ignore();

        cout<<"Course Name : ";
        cin.getline(c.name,50);

        cout<<"Credit : ";
        cin>>c.credit;

        courses[courseCount++]=c;
    }

    void admission()
    {
        Student s;

        cout<<"Student ID : ";
        cin>>s.id;

        cin.ignore();

        cout<<"Student Name : ";
        cin.getline(s.name,50);

        cout<<"Department : ";
        cin.getline(s.department,50);

        students[studentCount++]=s;
    }

    void registerCourse()
    {
        int sid,cid;

        cout<<"Student ID : ";
        cin>>sid;

        cout<<"Course ID : ";
        cin>>cid;

        for(int i=0;i<studentCount;i++)
        {
            if(students[i].id==sid)
            {
                for(int j=0;j<courseCount;j++)
                {
                    if(courses[j].id==cid)
                    {
                        students[i].courses[
                        students[i].totalCourse++]=courses[j];

                        students[i].calculateGPA();

                        cout<<"Course Registered\n";
                        return;
                    }
                }
            }
        }

        cout<<"Student/Course Not Found\n";
    }

    void searchStudent()
    {
        int id;

        cout<<"Enter ID : ";
        cin>>id;

        for(int i=0;i<studentCount;i++)
        {
            if(students[i].id==id)
            {
                students[i].transcript();
                return;
            }
        }

        cout<<"Student Not Found\n";
    }

    void sortByGPA()
    {
        sort(students,
             students+studentCount,
             [](Student a,Student b)
        {
            return a.gpa>b.gpa;
        });

        cout<<"\nStudents Sorted by GPA\n";

        for(int i=0;i<studentCount;i++)
        {
            cout<<students[i].id<<" "
                <<students[i].name<<" "
                <<students[i].gpa<<endl;
        }
    }

    void departmentStatistics()
    {
        for(int i=0;i<departmentCount;i++)
        {
            int s=0,t=0;

            for(int j=0;j<studentCount;j++)
            {
                if(strcmp(students[j].department,
                          departments[i].name)==0)
                    s++;
            }

            for(int j=0;j<teacherCount;j++)
            {
                if(strcmp(teachers[j].department,
                          departments[i].name)==0)
                    t++;
            }

            departments[i].studentCount=s;
            departments[i].teacherCount=t;

            departments[i].statistics();
        }
    }

    void save()
    {
        ofstream file("students.dat",ios::binary);

        file.write((char*)&studentCount,sizeof(studentCount));

        file.write((char*)students,
                   sizeof(Student)*studentCount);

        file.close();

        cout<<"Saved Successfully\n";
    }

    void load()
    {
        ifstream file("students.dat",ios::binary);

        if(!file)
            return;

        file.read((char*)&studentCount,sizeof(studentCount));

        file.read((char*)students,
                  sizeof(Student)*studentCount);

        file.close();
    }
};

int main()
{
    University u;

    u.load();

    int ch;

    do
    {
        cout<<"\n===== MINI UNIVERSITY ERP =====\n";
        cout<<"1.Department\n";
        cout<<"2.Teacher\n";
        cout<<"3.Course\n";
        cout<<"4.Student Admission\n";
        cout<<"5.Course Registration\n";
        cout<<"6.Search Student\n";
        cout<<"7.Sort By GPA\n";
        cout<<"8.Department Statistics\n";
        cout<<"9.Save\n";
        cout<<"10.Exit\n";

        cout<<"Choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            u.addDepartment();
            break;

        case 2:
            u.addTeacher();
            break;

        case 3:
            u.addCourse();
            break;

        case 4:
            u.admission();
            break;

        case 5:
            u.registerCourse();
            break;

        case 6:
            u.searchStudent();
            break;

        case 7:
            u.sortByGPA();
            break;

        case 8:
            u.departmentStatistics();
            break;

        case 9:
            u.save();
            break;

        case 10:
            u.save();
            break;
        }

    }while(ch!=10);

    return 0;
}
