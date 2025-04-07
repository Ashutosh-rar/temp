#include <iostream.h>  
#include <conio.h>     
#include <math.h>      

class Shape {  
public:
virtual void area() = 0;  
};
class Circle : public Shape {  
private:
float radius;
public:
Circle(float r) {
radius = r;
}
void area() {  
float result = M_PI * radius * radius;
cout << "Area of Circle: " << result << endl;
}
};
class Sphere : public Shape {  
private:
float radius;
public:
Sphere(float r) {
radius = r;
}
void area() {  
float result = 4 * M_PI * radius * radius;
cout << "Surface Area of Sphere: " << result << endl;
}
};
class Cylinder : public Shape {  
private:
float radius, height;
public:
Cylinder(float r, float h) {
radius = r;
height = h;
}
void area() { 
float result = 2 * M_PI * radius * (radius + height);
cout << "Surface Area of Cylinder: " << result << endl;
}
};
void main() {  
clrscr();  

Shape *s1 = new Circle(5);     
Shape *s2 = new Sphere(4);     
Shape *s3 = new Cylinder(3, 7); 
   
s1->area();
s2->area();
s3->area();

delete s1;
delete s2;
delete s3;

getch();  
}
