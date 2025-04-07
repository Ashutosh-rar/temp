#include <iostream.h>
#include <conio.h>
#include <string.h>
class Travels {
protected:
    int tno;
    char company[30];
public:
    void acceptTravels() {
        cout << "Enter Travel No: ";
        cin >> tno;
        cout << "Enter Company Name: ";
        cin >> company;
    }
    void displayTravels() {
        cout << "Travel No: " << tno << ", Company: " << company << "\n";
    }
};
class Route : public Travels {
protected:
    int rid;
    char source[20], dest[20];
public:
    void acceptRoute() {
        acceptTravels();
        cout << "Enter Route ID: ";
        cin >> rid;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> dest;
    }
    void displayRoute() {
        displayTravels();
        cout << "Route ID: " << rid << ", From: " << source << ", To: " << dest << "\n";
    }
};
class Reservation : public Route {
    int seats;
    char tclass[10], date[12];
    float fare;
public:
    void accept() {
        acceptRoute();
        cout << "Enter No. of Seats: ";
        cin >> seats;
        cout << "Enter Class: ";
        cin >> tclass;
        cout << "Enter Fare: ";
        cin >> fare;
        cout << "Enter Travel Date (dd-mm-yyyy): ";
        cin >> date;
    }
    void display() {
        displayRoute();
        cout << "Seats: " << seats << ", Class: " << tclass;
        cout << ", Fare: Rs." << fare << ", Date: " << date << "\n\n";
    }
    char* getDate() {
        return date;
    }
};
void main() {
    clrscr();
    Reservation r[10];
    int n, i;
    char searchDate[12];
    cout << "Enter number of reservations: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\nReservation " << i + 1 << ":\n";
        r[i].accept();
    }
    cout << "\nAll Reservations\n";
    for (i = 0; i < n; i++) {
        r[i].display();
    }
    cout << "\nEnter date to search (dd-mm-yyyy): ";
    cin >> searchDate;
    cout << "\nReservations on " << searchDate << "\n";
    for (i = 0; i < n; i++) {
        if (strcmp(r[i].getDate(), searchDate) == 0) {
            r[i].display();
        }
    }
    getch();
}
