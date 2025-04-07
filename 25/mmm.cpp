#include <iostream.h>
#include <conio.h>

inline float mean(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

inline int median(int a, int b, int c) {
    return (a > b) ? ((a < c) ? a : ((b > c) ? b : c)) : ((b < c) ? b : ((a > c) ? a : c));
}

inline int mode(int a, int b, int c) {
    return (a == b || a == c) ? a : ((b == c) ? b : -1);  // -1 means no mode
}

void main() {
    clrscr();
    int x, y, z;
    
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    cout << "\nMean: " << mean(x, y, z);
    cout << "\nMedian: " << median(x, y, z);
    
    int modeValue = mode(x, y, z);
    (modeValue != -1) ? cout << "\nMode: " << modeValue : cout << "\nNo Mode";

    getch();
}
