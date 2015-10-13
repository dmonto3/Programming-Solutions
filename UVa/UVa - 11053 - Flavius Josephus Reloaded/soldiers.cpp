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

#define D(x)// cout << "DEBUG: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef unsigned long long ull;
const int MAXN = 1000000000;
const int MAXIT = 1000000;

map <int, int> m;
vector <int> gen;


int main(){
   int n, a, b, acum;
   ull bign;
   ull current;
   while(cin >> n && n){
      m.clear(); gen.clear();
      cin >> a >> b;
      //cout << n;
      current = 0;
     // m[current]++;
      //gen.push_back(current);
      D(m[0]);
      while(true){
         bign = ((( (a % n) * current) % n) * current) % n + (b % n);
         current = bign % n;
         if(m[current] == 1){
            m[current]++;
            gen.push_back(current);
            break;
         }
         m[current]++;
         gen.push_back(current);
      //   D(current);
      //   D(m[current]);
      }
      for(int i = 0; i < gen.size(); ++i){
         if(gen[i] == gen[gen.size() - 1]){
           // D(gen[i]);
           // D(gen[gen.size() - 1]);
            cout << n - m.size() + i << endl;
            break;
         }
      }
   }
   return 0;
}
