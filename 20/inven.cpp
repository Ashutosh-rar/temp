#include <iostream.h>
#include <conio.h>
#include <string.h>

class Mobile {
char model[30], company[30], color[15];
float price;
int quantity;

public:
void accept() {
cout << "\nEnter Mobile Model: ";
cin >> model;
cout << "Enter Company Name: ";
cin >> company;
cout << "Enter Color: ";
cin >> color;
cout << "Enter Price: ";
cin >> price;
cout << "Enter Quantity: ";
cin >> quantity;
}

void sale(int qty) {
if (qty <= quantity) {
quantity -= qty;
cout << "\nSale successful! " << qty << " mobiles sold.\n";
} else {
cout << "\nStock not available!\n";
}
}

void purchase(int qty) {
quantity += qty;
cout << "\nPurchase successful! " << qty << " mobiles added to stock.\n";
}

void display() {
cout << "\nModel: " << model
<< "\nCompany: " << company
<< "\nColor: " << color
<< "\nPrice: " << price
<< "\nStock: " << quantity << "\n";
}

char* getModel() { return model; }
};

void main() {
clrscr();
int n, choice, qty;
char searchModel[30];

cout << "Enter number of mobile models: ";
cin >> n;

Mobile mobiles[n];  

for (int i = 0; i < n; i++) {
cout << "\nEnter details for Mobile " << i + 1 << ":\n";
mobiles[i].accept();
}

do {
cout << "\nMENU:\n1. Sale Mobile\n2. Purchase Mobile\n3. Display Inventory\n4. Exit\nEnter choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "\nEnter Model to Sale: ";
cin >> searchModel;
cout << "Enter Quantity to Sale: ";
cin >> qty;
for (int i = 0; i < n; i++) {
if (strcmp(mobiles[i].getModel(), searchModel) == 0) {
mobiles[i].sale(qty);
break;
}
}
break;

case 2:
cout << "\nEnter Model to Purchase: ";
cin >> searchModel;
cout << "Enter Quantity to Purchase: ";
cin >> qty;
for (int i = 0; i < n; i++) {
if (strcmp(mobiles[i].getModel(), searchModel) == 0) {
mobiles[i].purchase(qty);
break;
}
}
break;

case 3:
cout << "\n--- Mobile Inventory ---\n";
for (int i = 0; i < n; i++)
mobiles[i].display();
break;

case 4:
cout << "\nExiting program...\n";
break;

default:
cout << "\nInvalid choice!\n";
}
} while (choice != 4);

getch();
}
