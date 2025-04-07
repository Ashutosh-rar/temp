#include <iostream.h>
#include <conio.h>
#include <string.h>

class Student {
protected:
    int rollNo;
    char name[30];

public:
    void getStudent() {
        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
    }

    void showStudent() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
    }
};
class Theory : virtual public Student {
protected:
    int m1, m2, m3, m4;

public:
    void getTheory() {
        cout << "\nEnter Theory Marks (M1 M2 M3 M4): ";
        cin >> m1 >> m2 >> m3 >> m4;
    }

    void showTheory() {
        cout << "\nTheory Marks: " << m1 << " " << m2 << " " << m3 << " " << m4;
    }

    int getTheoryTotal() {
        return m1 + m2 + m3 + m4;
    }
};

class Practical : virtual public Student {
protected:
    int p1, p2;

public:
    void getPractical() {
        cout << "\nEnter Practical Marks (P1 P2): ";
        cin >> p1 >> p2;
    }

    void showPractical() {
        cout << "\nPractical Marks: " << p1 << " " << p2;
    }

    int getPracticalTotal() {
        return p1 + p2;
    }
};

class Result : public Theory, public Practical {
    int total;
    float percent;
    char grade;

public:
    void acceptAll() {
        getStudent();
        getTheory();
        getPractical();
    }

    void displayAll() {
        showStudent();
        showTheory();
        showPractical();
    }

    void calculateResult() {
        total = getTheoryTotal() + getPracticalTotal();
        percent = (float)total / 6;

        if (percent >= 75)
            grade = 'A';
        else if (percent >= 60)
            grade = 'B';
        else if (percent >= 50)
            grade = 'C';
        else if (percent >= 35)
            grade = 'D';
        else
            grade = 'F';

        cout << "\nTotal Marks: " << total;
        cout << "\nPercentage: " << percent << "%";
        cout << "\nGrade: " << grade;
    }
};

void main() {
    clrscr();

    Result r;
    int choice;

    do {
        cout << "\n\n===== Student Menu =====";
        cout << "\n1. Accept Student Information";
        cout << "\n2. Display Student Information";
        cout << "\n3. Calculate Result";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            r.acceptAll();
            break;
        case 2:
            r.displayAll();
            break;
        case 3:
            r.calculateResult();
            break;
        case 4:
        default:
            cout << "\nInvalid Choice!";
        }
    } while (choice != 4);

    getch();
}
