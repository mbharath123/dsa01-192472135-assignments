#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
class Complex{
 double r,i;
public:
 Complex():r(0),i(0){} Complex(double x):r(x),i(0){} Complex(double x,double y):r(x),i(y){}
 Complex operator+(const Complex& z)const{return {r+z.r,i+z.i};}
 Complex operator-(const Complex& z)const{return {r-z.r,i-z.i};}
 Complex operator*(const Complex& z)const{return {r*z.r-i*z.i,r*z.i+i*z.r};}
 Complex operator/(const Complex& z)const{double d=z.r*z.r+z.i*z.i;if(d==0)throw runtime_error("Division by zero impedance");return {(r*z.r+i*z.i)/d,(i*z.r-r*z.i)/d};}
 bool operator==(const Complex& z)const{return fabs(r-z.r)<1e-9&&fabs(i-z.i)<1e-9;}
 double magnitude()const{return sqrt(r*r+i*i);}
 friend ostream& operator<<(ostream& o,const Complex& z){return o<<z.r<<(z.i>=0?" + j":" - j")<<fabs(z.i);}
};
int main(){double w=100,R=10,L=.1,C=.001;Complex zr(R),zl(0,w*L),zc(0,-1/(w*C));Complex s=zr+zl+zc;cout<<"Series "<<s<<" magnitude "<<s.magnitude()<<'\\n';Complex x(10,5),y(20,-5);Complex p=(x*y)/(x+y);cout<<"Parallel "<<p<<" magnitude "<<p.magnitude()<<'\\n';try{Complex zero;cout<<(x/zero);}catch(const runtime_error& e){cout<<e.what()<<'\\n';}}
