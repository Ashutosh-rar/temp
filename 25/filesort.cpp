#include <iostream.h>
#include <fstream.h>
#include <conio.h>

void main() {
    clrscr();
    
    ifstream inFile("SampleData.txt");
    ofstream upperFile("Upper.txt"), lowerFile("Lower.txt"), digitFile("Digit.txt"), otherFile("Other.txt");
    
    if (!inFile) {
        cout << "Error opening SampleData.txt!";
        getch();
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (isupper(ch)) upperFile.put(ch);
        else if (islower(ch)) lowerFile.put(ch);
        else if (isdigit(ch)) digitFile.put(ch);
        else otherFile.put(ch);
    }

    cout << "Files created successfully!";
    
    inFile.close();
    upperFile.close();
    lowerFile.close();
    digitFile.close();
    otherFile.close();
    
    getch();
}
