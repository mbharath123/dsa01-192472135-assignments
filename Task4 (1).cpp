#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Staff{protected:string name;int id;double basic;static constexpr double DA=.42;
public:Staff(string n,int i,double b):name(n),id(i),basic(b){}virtual double pay()const=0;virtual ~Staff()=default;
void show()const{cout<<name<<" "<<id<<" "<<pay()<<'\\n';}};
class Professor:public Staff{double research;public:Professor(string n,int i,double b,double r):Staff(n,i,b),research(r){}double pay()const override{return basic+basic*DA+research;}};
class LabAssistant:public Staff{public:LabAssistant(string n,int i,double b):Staff(n,i,b){}double pay()const override{return basic+basic*DA;}};
class GuestFaculty:public Staff{double hours,rate;public:GuestFaculty(string n,int i,double h,double r):Staff(n,i,0),hours(h),rate(r){}double pay()const override{return hours*rate;}};
int main(){vector<unique_ptr<Staff>> v;v.push_back(make_unique<Professor>("Anu",1,50000,5000));v.push_back(make_unique<LabAssistant>("Ravi",2,30000));v.push_back(make_unique<GuestFaculty>("Maya",3,20,1000));for(auto& x:v)x->show();}
