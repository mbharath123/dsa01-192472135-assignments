#include <iostream>
#include <cstring>
using namespace std;
class Text{
 char* p;
public:
 Text(const char* s=""){p=new char[strlen(s)+1];strcpy(p,s);}
 Text(const Text& x){p=new char[strlen(x.p)+1];strcpy(p,x.p);}
 Text& operator=(const Text& x){if(this!=&x){char* q=new char[strlen(x.p)+1];strcpy(q,x.p);delete[] p;p=q;}return *this;}
 ~Text(){delete[] p;}
 Text operator+(const Text& x)const{char* q=new char[strlen(p)+strlen(x.p)+1];strcpy(q,p);strcat(q,x.p);Text r(q);delete[] q;return r;}
 bool operator==(const Text& x)const{return strcmp(p,x.p)==0;}
 bool operator!=(const Text& x)const{return !(*this==x);}
 friend ostream& operator<<(ostream& o,const Text& x){return o<<x.p;}
};
int main(){Text a("Hello "),b("World"),c=a+b;cout<<c<<'\\n';Text e;cout<<'['<<e<<"]\\n";a=a;Text d=c;cout<<boolalpha<<(d==c)<<' '<<(d!=b)<<'\\n';}
