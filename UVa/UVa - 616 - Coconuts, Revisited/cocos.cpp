using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x)// cout << #x " = " << (x) << endl;
typedef long long ll;

vector <ll> divisors;

void getDiv(ll n){
   divisors.clear();
   ll j = 1;
   for(ll i = 2; i*i <=n; ++i){
      if(n%i == 0LL){
         divisors.push_back(i);
      }
      j = i;
   }
   j++;
   if(n%j == 0)
      divisors.push_back(j);
}

bool work(ll coc, ll people){
   for(ll i = 1LL; i <= people; ++i){
      coc--;
      if(coc % people != 0) return false;
      coc = coc * (people - 1LL) / people;
   }
   return (coc % people == 0);
}

bool sol(ll coc){
   if(coc == 0LL){
      cout << "0 coconuts, no solution" << endl;
      return false;
   }
   getDiv(coc - 1);
   reverse(divisors.begin(), divisors.end());
   
   for(int i = 0; i < divisors.size(); ++i){
      if(work(coc, divisors[i])){
         cout << coc << " coconuts, " << divisors[i];
         cout << " people and 1 monkey" << endl;
         return true;
      }
   }
   cout << coc << " coconuts, no solution" << endl;
   return false;
}
  
int main(){
   ll coc;
   
   while(cin >> coc && coc >= 0){
      sol(coc);
   }
   return 0;
}
