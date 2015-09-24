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



int main(){
   int n, k, butts, total;
   while(cin >> n >> k){
      total = butts = 0;
      while(n){
         total += n;
         butts += n;
         n = butts / k;
         D(n); D(butts);
         butts %= k;
      }
      cout << total << endl;
   }
   return 0;
}
