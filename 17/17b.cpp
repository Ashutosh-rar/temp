#include <iostream.h>
#include <conio.h>
#include <string.h>
class Student {
public:
    int sid;
    char name[20], cls[10];
    void acceptS() {
        cout << "SID, Name, Class: ";
        cin >> sid >> name >> cls;
    }
    void displayS() {
        cout << sid << "\t" << name << "\t" << cls << "\t";
    }
};
class Competition {
public:
    int cid;
    char cname[20];
    void acceptC() {
        cout << "CID, CName: ";
        cin >> cid >> cname;
    }
    void displayC() {
        cout << cid << "\t" << cname << "\t";
    }
};
class StudComp : public Student, public Competition {
public:
    int rank;
    void accept() {
        acceptS();
        acceptC();
        cout << "Rank: "; cin >> rank;
    }
    void display() {
        displayS();
        displayC();
        cout << rank << "\n";
    }
};
void sortByRank(StudComp s[], int n, int cid) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (s[i].cid == cid && s[j].cid == cid && s[i].rank > s[j].rank) {
                StudComp temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }

    cout << "\nSorted Students for Competition ID " << cid << ":\n";
    cout << "SID\tName\tClass\tCID\tCName\tRank\n";
    for (i = 0; i < n; i++)
        if (s[i].cid == cid)
            s[i].display();
}
void main() {
    clrscr();
    StudComp s[10];
    int n = 0, ch, cid,i;
    do {
        cout << "\nMenu:\n1. Accept Info\n2. Display All\n3. Display Sorted by Rank\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "How many records? ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    cout << "\nEnter data for Student " << i + 1 << ":\n";
                    s[i].accept();
                }
                break;
            case 2:
                cout << "\nSID\tName\tClass\tCID\tCName\tRank\n";
                for (i = 0; i < n; i++)
                    s[i].display();
                break;
            case 3:
                cout << "Enter Competition ID to sort: ";
                cin >> cid;
                sortByRank(s, n, cid);
                break;
        }
    } while (ch != 4);
    getch();
}

