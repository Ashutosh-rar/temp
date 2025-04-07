#include <iostream.h>
#include <conio.h>

class Employee {
protected:
    int emp_code;
    char name[50];
    float salary;

public:
    Employee() { salary = 0; }  

    virtual void accept() {
        cout << "Enter Employee Code: ";
        cin >> emp_code;
        cout << "Enter Name: ";
        cin >> name;
    }

    virtual void calculateSalary() = 0;  
    virtual void display() {
        cout << "\nEmp Code: " << emp_code;
        cout << "\nName: " << name;
        cout << "\nSalary: " << salary << endl;
    }

    float getSalary() { return salary; }  
};

class Fulltime : public Employee {
    float daily_wages;
    int no_of_days;

public:
    void accept() {
        Employee::accept();
        cout << "Enter Daily Wages: ";
        cin >> daily_wages;
        cout << "Enter Number of Days Worked: ";
        cin >> no_of_days;
    }

    void calculateSalary() {
        salary = daily_wages * no_of_days;
    }
};

class Parttime : public Employee {
    int work_hours;
    float hourly_wages;

public:
    void accept() {
        Employee::accept();
        cout << "Enter Number of Work Hours: ";
        cin >> work_hours;
        cout << "Enter Hourly Wages: ";
        cin >> hourly_wages;
    }

    void calculateSalary() {
        salary = work_hours * hourly_wages;
    }
};

void main() {
    clrscr();

    Employee *emp[50];  
    int n, choice, i;
    char type;
    
    cout << "Enter Number of Employees: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter Employee Type (F for Fulltime, P for Parttime): ";
        cin >> type;

        if (type == 'F' || type == 'f')
            emp[i] = new Fulltime();
        else
            emp[i] = new Parttime();

        emp[i]->accept();
        emp[i]->calculateSalary();
    }

    do {
        cout << "\nMENU:";
        cout << "\n1. Display All Employees";
        cout << "\n2. Employee with Maximum Salary";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (i = 0; i < n; i++) {
                emp[i]->display();
            }
            break;

        case 2: {
            int maxF = -1, maxP = -1;
            float maxFSalary = 0, maxPSalary = 0;

            for (i = 0; i < n; i++) {
                Fulltime *f = dynamic_cast<Fulltime *>(emp[i]);
                Parttime *p = dynamic_cast<Parttime *>(emp[i]);

                if (f && f->getSalary() > maxFSalary) {
                    maxFSalary = f->getSalary();
                    maxF = i;
                }

                if (p && p->getSalary() > maxPSalary) {
                    maxPSalary = p->getSalary();
                    maxP = i;
                }
            }

            cout << "\nHighest Paid Fulltime Employee:";
            if (maxF != -1) emp[maxF]->display();

            cout << "\nHighest Paid Parttime Employee:";
            if (maxP != -1) emp[maxP]->display();

            break;
        }

        case 3:
            cout << "Exiting Program...";
            break;

        default:
            cout << "Invalid Choice!";
        }
    } while (choice != 3);

   
    for (i = 0; i < n; i++) {
        delete emp[i];
    }

    getch();
}
