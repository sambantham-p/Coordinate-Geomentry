#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<cmath>
#include<windows.h>
#include<ctime>
#include "coordinate.h"
using namespace std;
coordinate::coordinate()
{
    xcord=0;
    ycord=0;
}
void coordinate::pointinput()
{
    cout<<"Enter the points:\n(x1,y1): ";
    cin>>xcord>>ycord;
    cout<<endl;
}
void coordinate::line(coordinate c)
{
    int m,b;
    m=(c.xcord-xcord)/(c.ycord-ycord);
    b=ycord-m*xcord;
    if(b>=0)
        cout<<" y = "<<m<<"x"<<"+"<<b<<endl;
}
coordinate coordinate :: sumPoint(coordinate a)
{
    coordinate sum;
    sum.xcord=xcord+a.xcord;
    sum.ycord=ycord+a.ycord;
    return(sum);
}
coordinate coordinate :: subPoint(coordinate a)
{
    coordinate sub;
    sub.xcord=xcord-a.xcord;
    sub.ycord=ycord-a.ycord;
    return(sub);
}
coordinate coordinate :: mulPoint(coordinate a)
{
    coordinate mul;
    mul.xcord=a.xcord*xcord;
    mul.ycord=a.ycord*ycord;
    return(mul);
}
coordinate coordinate :: mulInt(int a)
{
    coordinate mut;
    mut.xcord=a*xcord;
    mut.ycord=a*ycord;
    return(mut);
}
float coordinate::distance(coordinate A)
{
    float Distance;
    Distance=sqrt(pow((A.xcord-xcord),2)+pow((A.ycord-ycord),2));
    return(Distance);
}
bool coordinate::isOrigin()
{
   if(xcord==0&&ycord==0)
   {
       return 1;
   }
   else
   {
       return 0;
   }
}
void coordinate::checkQuad()
{
    if(xcord==0)
       {
           if(ycord==0)
           {
               cout<<"Origin"<<endl;
           }
           else
                cout<<"Y_Axis"<<endl;
        }
    else if(ycord==0)
    {
        cout<<"X_Axis"<<endl;
    }
    else if(xcord>0&&ycord>0)
        cout<<"1st Coordinate"<<endl;
    else if(xcord<0&&ycord>0)
        cout<<"2nd Coordinate"<<endl;
    else if(xcord<0&&ycord<0)
        cout<<"3rd Coordinate"<<endl;
    if(xcord>0&&ycord<0)
        cout<<"4th Coordinate"<<endl;
}
void coordinate::display()
{
    cout<<"\nThe points are :\n";
    cout<<"(x,y)="<<"("<<xcord<<","<<ycord<<")"<<endl;
}
line::line():coordinate()
{
    m=0;
    b=0;
}
bool line::parallel(line c)
{
    if(m==c.m)
    {
        cout<<"\nThe line1 is y="<<m<<"x +"<<b<<" and the line 2 is y="<<c.m<<"x +"<<c.b<<" are parallel to each other"<<endl;
        return 1;
    }
    else
    {
        cout<<"\nThe line1 is y="<<m<<"x +"<<b<<" and the line 2 is y="<<c.m<<"x +"<<c.b<<" are not parallel to each other"<<endl;
        return 0;
    }
}
void line::lineinput()
{
    cout<<"Information regarding line 1:\n";
    cout<<"Enter the slope and constant of line 1: ";
    cin>>m>>b;
}
void line::perpendicular(line d)
{
    float s;
    s=m*d.m;
    if(s==-1.00)
    {
        cout<<"\nThe line1 is y="<<m<<"x +"<<b<<" and the line 2 is y="<<d.m<<"x +"<<d.b<<" are perpendicular to each other"<<endl;
    }
    else
         cout<<"\nThe line1 is y="<<m<<"x +"<<b<<" and the line 2 is y="<<d.m<<"x +"<<d.b<<" are not perpendicular to each other"<<endl;

}
void line::intersection(line p)
{
    float x,y;
    m=m*-1;
    p.m=p.m*-1;
    b=b*-1;
    p.b=p.b*-1;
    x=(p.b-b)/(m-p.m);
    y=(p.m*b-m*p.b)/(m-p.m);
    cout<<"\nThe intersection of two points y="<<m*-1<<"x +"<<b*-1<<" and y="<<p.m*-1<<"x +"<<p.b*-1<<" are ("<<x<<","<<y<<")"<<endl;
}
void line::distance(line l2)
{
    cout<<"O";
    float dis;
    dis=(abs(b-l2.b))/(sqrt(1+pow(m,2)));
    cout<<"\nThe shortest distance of the line1 is y="<<m<<"x +"<<b<<" and the line 2 is y="<<l2.m<<"x +"<<l2.b<<" is "<<dis<<" units";
}
void line::angle(line a)
{
    float angle,theta;
    angle=(abs(a.m-m))/(abs(1+m*a.m));
    theta=atan(angle);
    cout<<"\nThe angle between line y="<<m<<"x +"<<b<<" and the line y="<<a.m<<"x +"<<a.b<<":\n angle="<<theta<<" degree"<<endl;
}
Vector::Vector()
{
    xcord=0;
    ycord=0;
    zcord=0;
}
Vector Vector :: sumvector(Vector a)
{
    Vector sum;
    sum.xcord=xcord+a.xcord;
    sum.ycord=ycord+a.ycord;
    sum.zcord=zcord+a.zcord;
    return(sum);
}
Vector Vector :: subvector(Vector b)
{
    Vector sub;
    sub.xcord=b.xcord-xcord;
    sub.ycord=b.ycord-ycord;
    sub.zcord=b.zcord-zcord;
    return(sub);
}

void Vector::display()
{
    cout<<"\nThe points are :\n";
    cout<<"Xi +Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k "<<endl;
}
void Vector::collinear(Vector b)
{
    float collinear;
    collinear=(ycord*b.zcord-zcord*b.ycord)-(xcord*b.zcord-zcord*b.xcord)-(xcord*b.ycord-ycord*b.xcord);
    if(collinear==0)
    {
        cout<<"\nThe two vectors Xi + Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<b.xcord<<"i+ "<<b.ycord<<"j+ "<<b.zcord<<"k are collinear "<<endl;

    }
    else
        cout<<"\nThe two vectors Xi+Yj+Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<b.xcord<<"i+ "<<b.ycord<<"j+ "<<b.zcord<<"k are not collinear "<<endl;
}
void Vector::projection(Vector c)
{
    float d,e,proj;
    d=xcord*c.xcord+ycord*c.ycord+zcord*c.zcord;
    e=sqrt((c.xcord*c.xcord)+(c.ycord*c.ycord)+(c.zcord*c.zcord));
    proj=d/e;
    cout<<"Projection of "<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<c.xcord<<"i+ "<<c.ycord<<"j+ "<<c.zcord<<"k is : "<<proj;
}
void Vector::vectorinput()
{
    cout<<"Enter the scalars of i,j and k:\n(x1,y1,z1): ";
    cin>>xcord>>ycord>>zcord;
}
void Vector::parallel(Vector d)
{
    int p,q,r;
    p=xcord/d.xcord;
    q=ycord/d.ycord;
    r=zcord/d.zcord;
    if(p==1&&q==1&&r==1)
    {
        cout<<"\n The two vectors Xi +Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<d.xcord<<"i+ "<<d.ycord<<"j+ "<<d.zcord<<"k are parallel "<<endl;
    }
    else
    {
        cout<<"\n The two vectors Xi+Yj+Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<d.xcord<<"i+ "<<d.ycord<<"j+ "<<d.zcord<<"k are not parallel "<<endl;
    }
}
void Vector::perpendicular(Vector e,float angle)
{
    float s,d;
    d=xcord*e.xcord+ycord*e.ycord+zcord*e.zcord;
    s=d*cos(angle);
    if(s==0)
    {
        cout<<"\nThe two vectors Xi + Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<e.xcord<<"i+ "<<e.ycord<<"j+ "<<e.zcord<<"k are perpendicular "<<endl;
    }
    else
    {
        cout<<"\nThe two vectors Xi +Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<e.xcord<<"i+ "<<e.ycord<<"j+ "<<e.zcord<<"k are not perpendicular "<<endl;
    }
}
void Vector::scalarproduct(Vector f)
{
    float d;
    d=xcord*f.xcord+ycord*f.ycord+zcord*f.zcord;
    //s=d*cos(angle);
    cout<<"\nThe scalar product between the two vectors Xi +Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<f.xcord<<"i+ "<<f.ycord<<"j+ "<<f.zcord<<"k is"<<d<<endl;
}
void Vector::vectorproduct(Vector g,float angle)
{
    float s;
    float d1,d2;
    d1=sqrt(xcord*xcord+ycord*ycord+zcord*zcord);
    d2=sqrt(g.xcord*g.xcord+g.ycord*g.ycord+g.zcord*g.zcord);
    s=d1*d2*sin(angle);
    cout<<"\nThe magnitude vector product between the two vectors Xi +Yj +Zk = "<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<g.xcord<<"i+ "<<g.ycord<<"j+ "<<g.zcord<<"k is "<<s<<endl;
}
void Vector::boxproduct(Vector m,Vector n)
{
    float e;
    e=(xcord*((m.ycord*n.zcord)-(n.ycord*m.zcord)))-(ycord*((m.xcord*n.zcord)-(n.xcord*m.zcord)))+(zcord*((m.xcord*n.ycord)-(n.xcord*m.ycord)));
    cout<<"\nThe Box product between the three vectors Xi +Yj +Zk="<<xcord<<"i+ "<<ycord<<"j+ "<<zcord<<"k and "<<m.xcord<<"i+ "<<m.ycord<<"j+ "<<m.zcord<<"k and "<<n.xcord<<"i+ "<<n.ycord<<"j+ "<<n.zcord<<"k is"<<e<<endl;
}
Vector Vector::unit()
{
    Vector unit;
    float n;
    n=sqrt(pow(xcord,2)+pow(ycord,2)+pow(zcord,2));
    unit.xcord=xcord/n;
    unit.ycord=ycord/n;
    unit.zcord=zcord/n;
    return(unit);
}
void Account::Register()
{
    fstream fs("logindata.txt",ios::app);
    cout<<"\nEnter username: ";
    cin>>username;
    cout<<"\nEnter password: ";
    cin>>password;
    fs<<username<<" "<<password<<" ";
    fs.close();
}
int Account::login(string  un,string pw)
{
    string username,password;
    int flag=1;
    ifstream fs("logindata.txt",ios::in);
    ofstream t("log.txt",ios::app);
    while(!fs.eof())
    {
        fs>>username>>password;
        if(un==username && pw==password)
        {
            cout<<"Welcome  "<<username << " !" <<endl;
            return(1);
        }
    }
    fs.close();
    if(flag==1)
    {
        time_t  now=time(0);
        char*dt=ctime(&now);
        t<<dt;
        t.close();
        cout<<"Username or Password does not match. Try again later";
        return 0;
    }
    return 1;
}
