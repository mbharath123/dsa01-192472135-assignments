#include <iostream>
#include <string>
using namespace std;
class Book {
 string title, author; int copies;
 static int valid(int n){ return n<0?0:n; }
public:
 Book():Book("Untitled","Unknown",0){}
 explicit Book(const string& t):Book(t,"Unknown",1){}
 Book(const string& t,const string& a,int n):title(t),author(a),copies(valid(n)){}
 void show()const{cout<<title<<" | "<<author<<" | "<<copies<<'\\n';}
};
int main(){ Book a; Book b("C++ Basics"); Book c("OOP","Bjarne Stroustrup",5); Book d("Bad","Test",-3); a.show();b.show();c.show();d.show(); }
