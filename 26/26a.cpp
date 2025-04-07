#include <iostream.h>
#include <conio.h>
float average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}
float average(float x, float y, float z) {
    return (x + y + z) / 3;
}
void main() {
    clrscr();
    int a, b, c;
    float x, y, z;
    cout << "Enter 3 integer numbers: ";
    cin >> a >> b >> c;
    cout << "Average (int): " << average(a, b, c) << "\n";
    cout << "Enter 3 float numbers: ";
    cin >> x >> y >> z;
    cout << "Average (float): " << average(x, y, z);
    getch();
}
