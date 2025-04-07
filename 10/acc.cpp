#include <iostream.h>
#include <conio.h>

class Account {
int Acc_number;
char Acc_type[20];
float Balance;
public:
void accept() {
cout << "Enter Account Number: ";
cin >> Acc_number;
cout << "Enter Account Type: ";
cin >> Acc_type;
cout << "Enter Balance: ";
cin >> Balance;
}
void display() {
cout << "\nAccount Number: " << Acc_number;
cout << "\nAccount Type: " << Acc_type;
cout << "\nBalance: " << Balance << "\n";
}
};
void main() {
clrscr();
int n, i;
cout << "Enter the number of accounts: ";
cin >> n;
Account *acc = new Account[n];
for (i = 0; i < n; i++) {
cout << "\nEnter details for Account " << i + 1 << ":\n";
acc[i].accept();
}
cout << "\n----- Account Details -----\n";
for (i = 0; i < n; i++) {
cout << "\nAccount " << i + 1 << ":";
acc[i].display();
}
delete[] acc;
getch();
}
