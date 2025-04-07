#include<iostream.h>
#include<conio.h>
class sqaure
{
public:
int s;
void getdata()
{
cout<<"Enter side of square : ";
cin>>s;
}
int calarea()
{
return(s*s);
}
friend void compare(int s,int r);
};
class rectangle
{
public:
int l,w;
void getdata()
{
cout<<"Enter Length of Rectangle : ";
cin>>l;
cout<<"Enter Breadth of Rectangle : ";
cin>>w;
}
int calarea()
{
return(l*w);
}
friend void compare(int s,int r);
};
void compare(int s,int r)
{
if(s>r)
{
cout<<"\nThe area of sqaure is greater than area of rectangle"<<endl;
}
else
{
cout<<"\nThe area of rectangle is greater than area of sqaure"<<endl;
}
}
int main()
{
int s_area,r_area;
clrscr();
sqaure s;
rectangle r;
s.getdata();
s_area=s.calarea();
r.getdata();
r_area=r.calarea();
cout<<"\nSquare : " <<s_area<<endl;
cout<<"Rectangle : "<<r_area<<endl;
compare(s_area,r_area);
getch();
return 0;
}