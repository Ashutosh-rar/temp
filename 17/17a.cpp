#include <iostream.h>
#include <conio.h>
class MyMatrix {
    int a[10][10], r, c,i,j;
public:
    void accept() {
        cout << "Rows & Cols: "; cin >> r >> c;
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
    MyMatrix operator-(MyMatrix m) {
        MyMatrix temp;
        temp.r = r; temp.c = c;
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                temp.a[i][j] = a[i][j] - m.a[i][j];
        return temp;
    }
};
void main() {
    clrscr();
    MyMatrix m1, m2, m3;
    cout << "Matrix 1:\n"; m1.accept();
    cout << "Matrix 2:\n"; m2.accept();
    m3 = m1 - m2;
    cout << "\nSubtracted Matrix:\n"; m3.display();
    getch();
}