#include<iostream.h>
#include<conio.h> 
class matrix
{
    int a[5][5];
    int r,c,i,j;
    public:
matrix(int x,int y)
{
r=x;
c=y;
}
 ~matrix()
{
cout<<"destructor invoked";
}
void accept()
{
cout<<"Enter elements of matrix : ";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cin>>a[i][j];
}
}
}
void display()
{
cout<<"Element of matrix are : \n";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}
}
void transpose()
{
cout<<"\nTranspose of matrix is :\n ";
for(i=0;i<c;i++)
{
for(j=0;j<r;j++)
{
cout<<a[j][i]<<"\t";
}
cout<<endl;
}
}
};
int main()
{
int m,n;
clrscr();
cout<<"Enter order of matrix : ";
cin>>m>>n;
matrix obj1(m,n);
obj1.accept();
obj1.display();
obj1.transpose();
getch();
return 0;
}