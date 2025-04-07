#include <iostream.h>
#include <conio.h>

class Worker {
private:
    char name[50];
    int hours;
    float rate, salary;

public:
    Worker() { rate = 50; }  // Default Pay Rate = 50

    void getDetails() {
        cout << "Enter Worker Name: ";
        cin >> name;
        cout << "Enter Hours Worked: ";
        cin >> hours;
        cout << "Enter Pay Rate (Default = 50): ";
        cin >> rate;
    }

    void calculateSalary() {
        salary = hours * rate;
    }

    void showDetails() {
        cout << "\nWorker Name: " << name;
        cout << "\nHours Worked: " << hours;
        cout << "\nPay Rate: " << rate;
        cout << "\nTotal Salary: " << salary << endl;
    }
};

void main() {
    clrscr();

    Worker w;
    w.getDetails();
    w.calculateSalary();
    w.showDetails();

    getch();
}
