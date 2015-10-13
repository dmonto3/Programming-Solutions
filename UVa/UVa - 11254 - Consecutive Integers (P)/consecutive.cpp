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

#define D(x) cout << #x " = " << (x) << endl;
typedef long long ll;


vector <ll> divisors;

ll raiz(ll num){
   ll j = 1;
   for(ll i = 2; i*i <= num; ++i)
      j = i;
   return j;
}

ll good(ll num, ll first){
   ll aux = 1 - 4 * ( - first * first + first - 2 * num);
   if(aux < 0)
      return -1LL;
   double aux2 = sqrt(aux);
   if(aux2 != floor(aux2))
      return -1LL;
   aux2 = ( -1 + aux2) / 2;
   aux = (ll) aux2;
   if(aux < first)
      return -1LL;
   return aux;
}

bool res(ll num){
   for(int i = 1; i <= num; ++i){
      ll second = good(num, i);
      if(second != -1LL){
         cout << num << " = " << i << " + ... + " << second << endl;
         return true;
      }
   }
   return false;
}

int main(){
   ll n, first, last;
   while(cin >> n && n >= 0LL){
      bool b = res(n);
      if(!b)
         cout << n << " = " << n << " + ... + " << n << endl;
   }
   
   return 0;
}
