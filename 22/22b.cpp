#include <iostream.h>
#include <conio.h>
#include <string.h>
void display_str(char *s) {
    cout << "\"" << s << "\"" << endl;
}
void display_str(int n, char *s) {
    for (int i = 0; i < n && s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
}
void display_str(int m, int n, char *s) {
    for (int i = m; i <= n && s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
}
void main() {
    clrscr();
    char str[50];
    int n, m;
    cout << "Enter a string: ";
    cin >> str;
    cout << "\n1. Full string in quotes:\n";
    display_str(str);
    cout << "\n2. First 4 characters:\n";
    display_str(4, str);
    cout << "\n3. Substring from position 2 to 5:\n";
    display_str(2, 5, str);
    getch();
}
