#include <iostream.h>
#include <conio.h>
class Time {
    int hours, minutes, seconds;
public:
    friend istream& operator>>(istream &in, Time &t) {
        cout << "Enter Hours: ";
        in >> t.hours;
        cout << "Enter Minutes: ";
        in >> t.minutes;
        cout << "Enter Seconds: ";
        in >> t.seconds;
        return in;
    }
    friend ostream& operator<<(ostream &out, Time &t) {
        out << t.hours << "h:" << t.minutes << "m:" << t.seconds << "s";
        return out;
    }
    int operator!=(Time t2) {
        return (hours != t2.hours || minutes != t2.minutes || seconds != t2.seconds);
    }
};
void main() {
    clrscr();
    Time t1, t2;
    cout << "Enter First Time:\n";
    cin >> t1;
    cout << "\nEnter Second Time:\n";
    cin >> t2;
    cout << "\nFirst Time: " << t1 << "\n";
    cout << "Second Time: " << t2 << "\n";
    if (t1 != t2)
        cout << "\nTimes are NOT equal.";
    else
        cout << "\nTimes are equal.";
    getch();
}
