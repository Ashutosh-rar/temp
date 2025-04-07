#include <iostream.h>
#include <conio.h>

class Fraction {
    int num, den;

public:
    // Constructor to initialize fraction
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
    }

    // Function to add two fractions
    Fraction add(Fraction f) {
        int n = num * f.den + f.num * den;
        int d = den * f.den;
        return Fraction(n, d);
    }

    // Function to display fraction
    void display() {
        cout << num << "/" << den;
    }
};

void main() {
    clrscr();
    
    int n1, d1, n2, d2;
    cout << "Enter first fraction (numerator denominator): ";
    cin >> n1 >> d1;
    cout << "Enter second fraction (numerator denominator): ";
    cin >> n2 >> d2;

    Fraction f1(n1, d1), f2(n2, d2), sum;
    sum = f1.add(f2);

    cout << "\nSum of fractions: ";
    sum.display();

    getch();
}
