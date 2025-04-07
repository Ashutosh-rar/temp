#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

class City {

int City_code;
char City_name[30];
int population;

public:
void accept() {
cout << "Enter City Code: ";
cin >> City_code;
cout << "Enter City Name: ";
cin.ignore(); 
gets(City_name);
cout << "Enter Population: ";
cin >> population;
}

void display() {
cout << "\nCity Code: " << City_code;
cout << "\nCity Name: " << City_name;
cout << "\nPopulation: " << population << "\n";
}

int getPopulation() {
return population;
}

char* getCityName() {
return City_name;
}
};

void main() {
clrscr();
int n, i, j;
cout << "Enter the number of cities: ";
cin >> n;
City *cities = new City[n];
for (i = 0; i < n; i++) {
cout << "\nEnter details for City " << i + 1 << ":\n";
cities[i].accept();
}

for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (cities[j].getPopulation() > cities[j + 1].getPopulation()) {
City temp = cities[j];
cities[j] = cities[j + 1];
cities[j + 1] = temp;
}
}
}
cout << "\n--- Cities Sorted by Population ---\n";
for (i = 0; i < n; i++) {
cout << "\nCity " << i + 1 << ":";
cities[i].display();
}

char searchCity[30];
cout << "\nEnter the City Name to search: ";
cin.ignore();
gets(searchCity);
int found = 0;
for (i = 0; i < n; i++) {
if (strcmp(cities[i].getCityName(), searchCity) == 0) {
cout << "\nCity Found!\n";
cities[i].display();
found = 1;
break;
}
}
if (!found)
cout << "\nCity not found!\n";
delete[] cities;
getch();
}
