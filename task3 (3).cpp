#include <iostream>
using namespace std;
class Event {
 int rows,cols,booked; char** seats;
 bool valid(int r,int c)const{return seats&&r>=0&&r<rows&&c>=0&&c<cols;}
public:
 Event(int r,int c):rows(r>0?r:0),cols(c>0?c:0),booked(0),seats(nullptr){
  if(rows&&cols){seats=new char*[rows];for(int i=0;i<rows;++i){seats[i]=new char[cols];for(int j=0;j<cols;++j)seats[i][j]='O';}}
  cout<<"Created "<<rows<<" x "<<cols<<'\\n';
 }
 Event(const Event&)=delete; Event& operator=(const Event&)=delete;
 bool book(int r,int c){if(!valid(r,c)||seats[r][c]=='X')return false;seats[r][c]='X';++booked;return true;}
 bool cancel(int r,int c){if(!valid(r,c)||seats[r][c]=='O')return false;seats[r][c]='O';--booked;return true;}
 ~Event(){if(seats){for(int i=0;i<rows;++i)delete[] seats[i];delete[] seats;}cout<<"Closed; booked "<<booked<<'\\n';}
};
int main(){{Event e(2,3);e.book(0,0);e.book(1,2);e.cancel(0,0);}Event* p=new Event(3,4);p->book(1,1);delete p;Event z(0,5);}
