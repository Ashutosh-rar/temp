#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
class Employee {
    int empid;
    char name[20], company[20];
    float salary;
public:
    void accept() {
        cout << "\nEnter Emp ID: "; cin >> empid;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Company: "; cin >> company;
        cout << "Enter Salary: "; cin >> salary;
    }
    void display() {
        cout << "\nEmp ID   : " << empid;
        cout << "\nName     : " << name;
        cout << "\nCompany  : " << company;
        cout << "\nSalary   : " << setfill('*') << setw(7) << salary << "\n";
    }
};
void main() {
    clrscr();
    Employee e;
    e.accept();
    cout << "\nEmployee Information:\n";
    e.display();
    getch();
}