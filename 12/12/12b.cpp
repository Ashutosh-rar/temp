#include <iostream.h>
#include <conio.h>
class Weight {
    int kg, gm;
public:
    void get() {
        cout << "Enter weight (kg and gm): ";
        cin >> kg >> gm;
        normalize();
    }
    void display() {
        cout << kg << " kg " << gm << " gm" << endl;
    }
    void normalize() {
        if (gm >= 1000) {
            kg += gm / 1000;
            gm = gm % 1000;
        }
    }
    Weight operator+(Weight w) {
        Weight temp;
        temp.kg = kg + w.kg;
        temp.gm = gm + w.gm;
        temp.normalize();
        return temp;
    }
    int operator==(Weight w) {
        return (kg == w.kg && gm == w.gm);
    }
};

void main() {
    clrscr();
    Weight w1, w2, w3;
    cout << "\nEnter first weight:\n";
    w1.get();
    cout << "\nEnter second weight:\n";
    w2.get();
    cout << "\nFirst Weight: ";
    w1.display();
    cout << "Second Weight: ";
    w2.display();
    w3 = w1 + w2;
    cout << "\nSum of Weights: ";
    w3.display();
    if (w1 == w2)
        cout << "\nBoth weights are equal.";
    else
        cout << "\nWeights are not equal.";
    getch();
}

