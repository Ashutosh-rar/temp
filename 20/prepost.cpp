#include <iostream.h>
#include <conio.h>

class Number {
    int num;

public:
    Number(int n = 0) { num = n; }  // Constructor

    // Pre-increment (++num)
    Number operator++() {
        ++num;
        return *this;
    }

    // Post-increment (num++)
    Number operator++(int) {
        Number temp = *this;
        num++;
        return temp;
    }

    void display() { cout << "Number: " << num << "\n"; }
};

void main() {
    clrscr();
    
    Number n1(5);
    
    cout << "Before increment: ";
    n1.display();

    ++n1;  // Pre-increment
    cout << "After pre-increment: ";
    n1.display();

    n1++;  // Post-increment
    cout << "After post-increment: ";
    n1.display();

    getch();
}
