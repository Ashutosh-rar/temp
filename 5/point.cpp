#include <iostream.h>
#include <conio.h>

class Point
{
    int x, y;
public:
    void setpoint(int, int); 
    void showpoint();  
};

void Point::setpoint(int a, int b)
{
    x = a;
    y = b;
}


void Point::showpoint()
{
    cout << "(" << x << ", " << y << ")";
}
void main()
{
    clrscr();
    Point P;
    P.setpoint(5, 10);
    cout << "The coordinates of point P are: ";
    P.showpoint();
    
    getch();
}