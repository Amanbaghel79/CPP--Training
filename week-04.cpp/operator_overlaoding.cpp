#include<iostream>
using namespace std;
class complex{
    private:
    int real;
    int img;    
    public:
    complex():real(0),img(0){}
    complex(int r,int i): real(r),img(i){}
    void showdata(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }

    //Pre-increment operator.
    complex& operator ++(){ 
        ++real;
        return *this;
    }

    //Post-increment operator.
    complex operator ++(int){ 
        complex temp=*this; //if we dont create temp then it will not work properly.
        real++;
        return temp;
    }

    //Subtraction
    complex operator-(complex other){
        complex temp;
        temp.real=this->real-other.real;
        temp.img=this->img-other.img;
        return temp;
    }

    //Addition
    complex operator+(complex &other){
        complex temp;
        temp.real=this->real+other.real;
        temp.img=this->img+other.img;
        return temp;
    }

    //Multiplication
    complex operator *(complex &other){
        complex t;
        t.real= (this->real*other.real)-(this->img*other.img);
        t.img= (this->real*other.img)+(this->img*other.real);
        return t;
    }
};
int main(){
//    complex c1(5,6);
   complex c1(1,2);
   complex c2(2,3);
//    ++c1;  //pre increment operator. 
//    c1++; //post increment operator.
//    complex c2=c1++;
//       c2.showdata();
//       c1.showdata();
//    complex c3= c1-c2;
//  complex c4=c1+c2;
//    complex c5=c1.operator+(c2); // 2nd way to call.
//    c1.showdata();
//  c2=++c1; // c2=c1.operator++() ;
//  c5.showdata();
 }
 //Operators that can't be overloaded--> sizeof , :: , :? , . , .*
 