#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Account{public:virtual double rate()const{return 3.5;}virtual ~Account(){cout<<"Account destroyed\\n";}};
class SeniorAccount:public Account{double* history;public:SeniorAccount():history(new double[100]){}double rate()const override{return 4.0;}~SeniorAccount()override{delete[] history;cout<<"Senior destroyed\\n";}};
int main(){vector<unique_ptr<Account>> a;a.push_back(make_unique<Account>());a.push_back(make_unique<SeniorAccount>());for(auto& x:a)cout<<x->rate()<<'\\n';}
