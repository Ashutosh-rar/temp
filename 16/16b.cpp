#include <iostream.h>
#include <conio.h>
class Matrix {
    int a[10][10], r, c,i,j;
public:
    void accept() {
        cout << "Enter rows & cols: "; cin >> r >> c;
        cout << "Enter elements:\n";
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                cin >> a[i][j];
    }
    void display() {
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++)
                cout << a[i][j] << "\t";
            cout << "\n";
        }
    }
    void operator-() {
        cout << "\nTranspose:\n";
        for (i = 0; i < c; i++) {
            for (j = 0; j < r; j++)
                cout << a[j][i] << "\t";
            cout << "\n";
        }
    }
    void operator++() {
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                a[i][j]++;
    }
};
void main() {
    clrscr();
    Matrix m;
    m.accept();
    cout << "\nOriginal:\n"; m.display();
    ++m;
    cout << "\nAfter Increment:\n"; m.display();
    -m;
    getch();
}