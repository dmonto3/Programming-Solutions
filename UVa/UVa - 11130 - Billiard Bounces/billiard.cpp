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


int main(){
   double a, b, v, alpha, s, distance, xTotal, yTotal;
   int x, y;
   while(cin >> a >> b >> v >> alpha >> s && (a || b || v || alpha || s)){
      distance = 0.5 * v * s;
      x = y = 0;
      xTotal = distance * cos(alpha * PI / 180);
      yTotal = distance * sin(alpha * PI / 180);
      
      xTotal -= a / 2;
      if(xTotal >= 0.0){
         x++;
         x += (int) floor( xTotal / a );
      }
      
      yTotal -= b / 2;
      if(yTotal >= 0.0){
         y++;
         y += (int) floor( yTotal / b );
      }
      
      cout << x << " " << y << endl;
   }
   return 0;
}
