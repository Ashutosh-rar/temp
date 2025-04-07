#include <iostream.h>
#include <conio.h>

class Seller {
    char name[30], product[30], month[15];
    int salesQty, targetQty;
    float commission;

public:
    void accept() {
        cout << "\nEnter Seller Name: ";
        cin >> name;
        cout << "Enter Product Name: ";
        cin >> product;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Enter Sales Quantity: ";
        cin >> salesQty;
        cout << "Enter Target Quantity: ";
        cin >> targetQty;
        calculateCommission();
    }

    void calculateCommission() {
        if (salesQty > targetQty)
            commission = (0.25 * (salesQty - targetQty)) + (0.1 * targetQty);
        else if (salesQty == targetQty)
            commission = 0.1 * targetQty;
        else
            commission = 0;
    }

    void display() {
        cout << "\nSeller: " << name
             << "\nProduct: " << product
             << "\nMonth: " << month
             << "\nSales: " << salesQty
             << "\nTarget: " << targetQty
             << "\nCommission: " << commission << "\n";
    }
};

void main() {
    clrscr();
    int n;
    cout << "Enter number of sellers: ";
    cin >> n;

    Seller s[n];  // Array of objects

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Seller " << i + 1 << ":\n";
        s[i].accept();
    }

    cout << "\n--- Seller Details & Commission ---\n";
    for (int i = 0; i < n; i++)
        s[i].display();

    getch();
}
