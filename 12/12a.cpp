#include <iostream.h>
#include <conio.h>
#include <string.h>

class Date {
    int day, month, year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    char* getMonthName(int m) {
        static char* months[] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        if (m >= 1 && m <= 12)
            return months[m - 1];
        else
            return "Invalid";
    }
    void display() {
        if (day < 10) cout << "0";
        cout << day << "-";
        cout << getMonthName(month) << "-";
        cout << year << endl;
    }
};

void main() {
    clrscr();

    int d, m, y;
    cout << "Enter date (dd mm yyyy): ";
    cin >> d >> m >> y;

    Date customDate(d, m, y);

    cout << "\nFormatted Date: ";
    customDate.display();

    getch();
}