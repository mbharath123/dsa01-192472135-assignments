#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cart{string items[10];double prices[10];int n=0;double discount=0;
public:Cart& add(const string& item,double price){if(n<10&&price>=0){items[n]=item;prices[n++]=price;}return *this;}
Cart& setDiscount(double discount){this->discount=discount<0?0:(discount>100?100:discount);return *this;}
double total()const{double t=0;for(int i=0;i<n;++i)t+=prices[i];return t*(100-discount)/100;}};
int main(){Cart c;c.add("Rice",60).add("Dal",120).setDiscount(10);Cart* p=&c;p->add("Oil",180);cout<<fixed<<setprecision(2)<<p->total()<<'\\n';Cart other;other.add("Milk",50);Cart& ref=other;ref.add("Bread",40);Cart* heap=new Cart;heap->add("Tea",100);delete heap;Cart* a[]={&c,&other};Cart* best=a[0];for(auto x:a)if(x->total()>best->total())best=x;cout<<best->total()<<'\\n';}
