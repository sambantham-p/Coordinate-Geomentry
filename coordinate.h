#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
class coordinate
{
    protected:
        int xcord,ycord;
    public:
        coordinate();
        //coordinate(int,int);
        void pointinput();
        void line(coordinate);
        void vector(coordinate);
        coordinate sumPoint(coordinate);
        coordinate mulPoint(coordinate);
        coordinate mulInt(int);
        coordinate subPoint(coordinate);
        float distance(coordinate);
        bool isOrigin();
        void checkQuad();
        void display();
};
class line: public coordinate
{
    private:
        float m,b;

    public:
        line();
        //line(float,float);
        bool parallel(line);
        void lineinput();
        void perpendicular(line);
        void distance(line);
        void intersection(line);
        void angle(line);
};
class Vector:public coordinate
{
    private:
        int zcord;

    public:
        Vector();
        //Vector(int,int,int);
        void vectorinput();
        Vector sumvector(Vector);
        Vector subvector(Vector);
        void collinear(Vector);
        void projection(Vector);
        Vector unit();
        void parallel(Vector);
        void perpendicular(Vector,float);
        void vectorproduct(Vector,float);
        void scalarproduct(Vector);
        void boxproduct(Vector,Vector);
        void display();
};
class Account
{

        protected:
            string username;
            string password;

        public:

            void Register();
            int login(string un,string pw);
};
#endif // COORDINATE_H_INCLUDED
