#include <iostream.h>
#include <conio.h>
class Point {
    int x, y;
public:
    Point(int a = 0, int b = 0) { x = a; y = b; }
    void accept() {
        cout << "\nEnter x and y: ";
        cin >> x >> y;
    }
    void display() {
        cout << "(" << x << "," << y << ")\n";
    }
    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator-() {
        return Point(-x, -y);
    }
    Point operator*(int n) {
        return Point(x * n, y * n);
    }
};
void main() {
    clrscr();
    Point p1, p2, p3;
    int n;
    cout << "Enter Point 1:";
    p1.accept();
    cout << "Enter Point 2:";
    p2.accept();
    p3 = p1 + p2;
    cout << "\nAddition: ";
    p3.display();
    p3 = -p1;
    cout << "Negated Point 1: ";
    p3.display();
    cout << "Enter constant to multiply: ";
    cin >> n;
    p3 = p1 * n;
    cout << "Point1 * " << n << ": ";
    p3.display();
    getch();
}