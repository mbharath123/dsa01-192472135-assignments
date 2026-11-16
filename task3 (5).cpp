#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
class Time{
 int s;
public:
 Time(int h=0,int m=0,int x=0):s(h*3600+m*60+x){}
 Time& operator++(){++s;return *this;}
 Time operator++(int){Time old=*this;++s;return old;}
 bool operator==(const Time& x)const{return s==x.s;}
 bool operator<(const Time& x)const{return s<x.s;}
 friend ostream& operator<<(ostream& o,const Time& t){return o<<t.s/3600<<':'<<(t.s/60)%60<<':'<<t.s%60;}
};
class Playlist{
 vector<string> v;
public:
 Playlist(initializer_list<string> x):v(x){}
 string& operator[](int i){if(i<0||i>=int(v.size()))throw out_of_range("Playlist index out of range");return v[i];}
 const string& operator[](int i)const{if(i<0||i>=int(v.size()))throw out_of_range("Playlist index out of range");return v[i];}
};
int main(){Time t(0,59,59);Time a=t++;Time b=++t;cout<<a<<' '<<b<<' '<<t<<'\\n';Playlist p{"One","Two"};cout<<p[0]<<'\\n';try{cout<<p[-1];}catch(const out_of_range& e){cout<<e.what()<<'\\n';}}
