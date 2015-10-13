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

const int MAXN = 10000;

int niter [MAXN + 5];

int main(){
   int z, i, m, l, cases = 1, iteracion;
   
   while(cin >> z >> i >> m >> l && (z || i || m || l)){
      cout << "Case " << cases++ << ": ";
      for(int j = 0; j < MAXN; ++j){
         niter[j] = 0;
      }
      iteracion = 1;
      while(true){
         if(niter[l] != 0){
            break;
         }
         niter[l] = iteracion++;
         l = (z * l + i) % m;
      }
      cout << iteracion - niter[l] << endl;
   }
   return 0;
}
