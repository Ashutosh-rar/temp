#include <iostream.h>
#include <conio.h>
class College {
    int id;
    char name[50], university[50];
    int est_year;
public:
    friend istream& operator>>(istream&, College&);
    friend ostream& operator<<(ostream&, College&);
};
istream& operator>>(istream&, College &c) {
    cout << "\nEnter College ID: ";
    cin >> c.id;
    cout << "Enter College Name: ";
    cin >> c.name;
    cout << "Enter Establishment Year: ";
    cin >> c.est_year;
    cout << "Enter University Name: ";
    cin >> c.university;
    return cin;
}
ostream& operator<<(ostream&, College &c) {
    cout << "\nCollege ID: " << c.id;
    cout << "\nCollege Name: " << c.name;
    cout << "\nEstablishment Year: " << c.est_year;
    cout << "\nUniversity Name: " << c.university;
    return cout;
}
void main() {
    clrscr();
    College c;
    cin >> c;
    cout << "\nCollege Information";
    cout << c;
    getch();
}
