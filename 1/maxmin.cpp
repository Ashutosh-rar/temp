#include<iostream.h>
#include<conio.h>


inline int findMax(int a, int b) {
    return (a > b) ? a : b;
}

inline int findMin(int a, int b) {
    return (a < b) ? a : b;
}

void main() {
    int num1, num2;
    clrscr();

    cout << "Enter two integer numbers: ";
    cin >> num1 >> num2;

    cout << "Maximum: " << findMax(num1, num2) << endl;
    cout << "Minimum: " << findMin(num1, num2) << endl;

    getch();
}
