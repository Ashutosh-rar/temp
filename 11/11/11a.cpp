#include <iostream.h>
#include <conio.h>

class MyArray {
    int* arr;
    int size;

public:
    MyArray(int s) {
        size = s;
        arr = new int[size];
        cout << "\nEnter " << size << " array elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    void displaySum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "\nSum of array elements: " << sum << "\n";
    }
    ~MyArray() {
        delete[] arr;
        cout << "Memory released.\n";
    }
};

void main() {
    clrscr();
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    MyArray obj(n);
    obj.displaySum();

    getch();
}
