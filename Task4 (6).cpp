#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Vehicle{protected:string reg;double rate;bool rented=false;public:Vehicle(string r,double d):reg(r),rate(d){}virtual double charge(int days)const=0;virtual string type()const=0;virtual ~Vehicle()=default;bool rent(){if(rented)return false;rented=true;return true;}double giveBack(int late){if(!rented)return 0;rented=false;return charge(1)+late*rate*.5;}void show()const{cout<<type()<<" "<<reg<<" "<<(rented?"Rented":"Available")<<'\\n';}};
class Bicycle:public Vehicle{public:Bicycle(string r,double d):Vehicle(r,d){}double charge(int n)const override{return rate*n;}string type()const override{return "Bicycle";}};
class MotorVehicle:public Vehicle{protected:double fuel;string service;public:MotorVehicle(string r,double d,double f,string s):Vehicle(r,d),fuel(f),service(s){}};
class TwoWheeler:public MotorVehicle{public:TwoWheeler(string r,double d,double f,string s):MotorVehicle(r,d,f,s){}double charge(int n)const override{return rate*n;}string type()const override{return "TwoWheeler";}};
class Car:public MotorVehicle{protected:int seats;public:Car(string r,double d,double f,string s,int x):MotorVehicle(r,d,f,s),seats(x){}double charge(int n)const override{return rate*n;}string type()const override{return "Car";}};
class ElectricCar:public Car{double battery,kwh;public:ElectricCar(string r,double d,double f,string s,int x,double b,double k):Car(r,d,f,s,x),battery(b),kwh(k){}double charge(int n)const override{return rate*n+battery*kwh*.01;}string type()const override{return "ElectricCar";}};
class ElectricBus:public Vehicle{int seats;public:ElectricBus(string r,double d,int s):Vehicle(r,d),seats(s){}double charge(int n)const override{return rate*n+seats*2;}string type()const override{return "ElectricBus";}};
int main(){vector<unique_ptr<Vehicle>> v;v.push_back(make_unique<Bicycle>("BI01",100));v.push_back(make_unique<TwoWheeler>("TW01",250,5,"2026-12-01"));v.push_back(make_unique<Car>("CA01",1200,30,"2026-12-10",5));v.push_back(make_unique<ElectricCar>("EV01",1500,80,"2026-12-15",5,60,8));v.push_back(make_unique<ElectricBus>("EB01",3000,30));for(auto& x:v){x->show();x->rent();cout<<x->charge(2)<<'\\n';}cout<<"Late return total "<<v[0]->giveBack(2)<<'\\n';}
