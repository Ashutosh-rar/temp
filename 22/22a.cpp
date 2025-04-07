#include <iostream.h>
#include <conio.h>
int square(int x) {
    return x * x;
}
float square(float x) {
    return x * x;
}
int cube(int x) {
    return x * x * x;
}
float cube(float x) {
    return x * x * x;
}
void main() {
    clrscr();
    int a = 4;
    float b = 2.5;
    cout << "Square of " << a << ": " << square(a) << "\n";
    cout << "Cube of " << a << ": " << cube(a) << "\n";
    cout << "Square of " << b << ": " << square(b) << "\n";
    cout << "Cube of " << b << ": " << cube(b) << "\n";
    getch();
}
