#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <conio.h>
class Machine {
    int id;
    char name[20];
    float price;
public:
    Machine(int i, const char *n, float p) {
        id = i;
        strcpy(name, n);
        price = p;
    }
    Machine(Machine &m) {
        id = m.id;
        strcpy(name, m.name);
        price = m.price;
    }
    void display() {
        cout << setw(10) << "ID" << setw(15) << "Name" << setw(12) << "Price\n";
	cout << setw(10) << id << setw(15) << name << setw(12) << setprecision(2) << price << "\n";
    }
};
void main() {
    clrscr();
    Machine m1(101, "drill", 125.55555);
    Machine m2 = m1;
    cout << "Machine Details:\n";
    m2.display();
    getch();
}
