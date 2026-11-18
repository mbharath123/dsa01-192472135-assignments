#include <iostream>
#include <string>
using namespace std;
class Address{string city;int pin;public:Address(string c,int p):city(c),pin(p){}string str()const{return city+"-"+to_string(pin);}};
class Person{protected:string name;int age;Address home;public:Person(string n,int a,string c,int p):name(n),age(a),home(c,p){cout<<"Person+ ";}virtual ~Person(){cout<<"Person- ";}};
class Student:public Person{long long reg;string course;public:Student(string n,int a,long long r,string c,int p,string co):Person(n,a,c,p),reg(r),course(co){cout<<"Student+ ";}~Student()override{cout<<"Student- ";}void print()const{cout<<reg<<" "<<name<<" ("<<age<<") "<<home.str()<<'\\n';}};
class Staff:public Person{public:Staff(string n,int a,string c,int p):Person(n,a,c,p){cout<<"Staff+ ";}~Staff()override{cout<<"Staff- ";}};
int main(){Student s("Kavya",19,192311001,"Salem",636001,"CSE");s.print();Staff st("Arun",35,"Chennai",600001);}
