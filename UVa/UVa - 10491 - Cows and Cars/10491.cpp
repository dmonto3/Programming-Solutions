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
typedef long long ll;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int main(){
   int cows, cars, shown, total;
   double res;
   while(cin >> cows >> cars >> shown){
      total = cows + cars;
      res = 1.0*cows / total * 1.0*cars / (total - 1 - shown) + 1.0*cars / total * 1.0*(cars - 1) / (total - 1 - shown);
      printf("%.5lf\n", res);
   }
   return 0;
}
