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

const int MAXN = 500000;
int lastCard [MAXN + 5];

int
main() {
   for(int i = 0; i <= MAXN; ++i)
      lastCard[i] = 0;
   lastCard[1] = 1;
   
   for(int i = 2; i <= MAXN; i *= 2){
      lastCard[i] = i;
   }
   
   int last = 2;
   for(int i = 3; i <= MAXN; ++i){
      if(lastCard[i] != 0){
         last = 2;
         continue;
      }
      lastCard[i] = last;
      last += 2;
   }
	
	int n;
	while(cin >> n && n)
	  cout << lastCard[n] << endl;
	return 0;
}
