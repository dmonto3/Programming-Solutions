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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef unsigned long long ull;

const int MAXN = 100000;

bool niter[MAXN + 5];

int main(){
   string s, res;
   int n, acum;
   while(cin >> s){
      if(s == "0"){
         break;
      }
      n = toInt(s);
      acum = 0;
      for(int i = 0; i < MAXN; ++i){
         niter[i] = false;
      }
      while(true){
         if(niter[n]){
            break;
         }
         niter[n] = true;
         acum++;
         s = toStr(n * n);
         
         res = "";
         for(int i = s.size(); i < 8; ++i){
            res += "0";
         }
         res += s;
         s = res.substr(2, 4);
         n = toInt(s);
      }
      cout << acum << endl;
   }
      
   return 0;
}
