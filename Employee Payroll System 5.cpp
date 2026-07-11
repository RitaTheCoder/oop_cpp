#include <iostream>
#include <algorithm>
using namespace std;

class Employee
{
private:
    int empID;
    string name;
    string designation;
    float salary,houseRent,medical,tax,netSalary;

public:
    void input()
    {
        cout << "\nEnter Employee ID: ";
        cin >> empID;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Basic Salary: ";
        cin >> salary;
    }

    void calculate()
    {
        houseRent = salary * 0.20;
        medical = salary * 0.10;
        tax = salary * 0.05;

        netSalary = salary + houseRent + medical - tax;
    }

    float getNetSalary()
    {
        return netSalary;
    }

    void display()
    {
        cout << "\n----------------------------------";
        cout << "\nEmployee ID       : " << empID;
        cout << "\nName              : " << name;
        cout << "\nDesignation       : " << designation;
        cout << "\nBasic Salary      : " << salary;
        cout << "\nHouse Rent        : " << houseRent;
        cout << "\nMedical Allowance : " << medical;
        cout << "\nTax               : " << tax;
        cout << "\nNet Salary        : " << netSalary;
        cout << "\n----------------------------------";
    }
};

int main()
{
    Employee emp[20];
    int n;

    cout << "Enter Number of Employees: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEmployee " << i + 1 << endl;
        emp[i].input();
        emp[i].calculate();
    }

    // Sort by Net Salary (Highest to Lowest)
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(emp[i].getNetSalary() < emp[j].getNetSalary())
            {
                swap(emp[i], emp[j]);
            }
        }
    }

    cout << "\n\n===== Employees Sorted by Net Salary =====\n";

    for(int i = 0; i < n; i++)
    {
        emp[i].display();
    }

    return 0;

}
