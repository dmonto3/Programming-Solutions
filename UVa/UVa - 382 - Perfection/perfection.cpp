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

void sol(int n){
   int acum = 0;
   for(int i = 1; i*i <=n; ++i){
      if(n%i == 0 && i != n){
         acum += i;
         if(i*i < n && n/i != n)
            acum += n/i;
      }
   }
   string s = toStr(n);
   string aux = "";
   for(int i = 0; i < 5 - s.size(); ++i){
      aux += " ";
   }
   cout << aux << s << "  ";
   if(n == acum)
      cout << "PERFECT";
   if(n > acum)
      cout << "DEFICIENT";
   if(n < acum)
      cout << "ABUNDANT";
   cout << endl;
}

int main(){
   cout << "PERFECTION OUTPUT" << endl;
   int n;
   while(cin >> n && n)
      sol(n);
   cout << "END OF OUTPUT" << endl;
   return 0;
}
