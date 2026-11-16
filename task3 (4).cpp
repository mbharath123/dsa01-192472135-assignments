#include <iostream>
#include <iomanip>
using namespace std;
class Money{
 long long paise;
 Money(long long p,bool):paise(p){}
public:
 Money(long long r=0,int p=0):paise(r*100+p){}
 Money operator+(const Money& x)const{return Money(paise+x.paise,true);}
 Money operator-(const Money& x)const{return Money(paise-x.paise,true);}
 Money& operator+=(const Money& x){paise+=x.paise;return *this;}
 bool operator==(const Money& x)const{return paise==x.paise;}
 friend ostream& operator<<(ostream& o,const Money& m){long long v=m.paise<0?-m.paise:m.paise;if(m.paise<0)o<<'-';return o<<"Rs "<<v/100<<'.'<<setw(2)<<setfill('0')<<v%100<<setfill(' ');}
};
int main(){Money a(120,75),b(79,25),c=a+b;cout<<c<<'\\n'<<boolalpha<<(c==Money(200))<<'\\n';cout<<(Money(0,75)+Money(0,50))<<'\\n';cout<<(Money(1)-Money(2))<<'\\n';}
