#include <iostream>
#include <string>
using namespace std;
class Person{protected:string name,phone;int id;public:Person(string n,int i,string p):name(n),phone(p),id(i){}virtual ~Person()=default;};
class Student:virtual public Person{protected:string programme;double cgpa;public:Student(string n,int i,string p,string pr,double g):Person(n,i,p),programme(pr),cgpa(g){}};
class Staff:virtual public Person{protected:string dept;double salary;public:Staff(string n,int i,string p,string d,double s):Person(n,i,p),dept(d),salary(s){}};
class TeachingAssistant:public Student,public Staff{public:TeachingAssistant(string n,int i,string p,string pr,double g,string d,double s):Person(n,i,p),Student(n,i,p,pr,g),Staff(n,i,p,d,s){}void show()const{cout<<name<<" "<<id<<" "<<phone<<" "<<programme<<" "<<cgpa<<" "<<dept<<" "<<salary<<'\\n';}};
class ResearchScholar:public Student{double fellowship;public:ResearchScholar(string n,int i,string p,string pr,double g,double f):Person(n,i,p),Student(n,i,p,pr,g),fellowship(f){}void show()const{cout<<name<<" fellowship "<<fellowship<<'\\n';}};
int main(){TeachingAssistant t("Kavya",1,"9876543210","CSE",8.8,"AI",25000);t.show();ResearchScholar r("Arun",2,"9876500000","CSE",9.1,12000);r.show();}
