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
using namespace std;

const int MAXN = 10005;

string seq[MAXN];
int times[10];

void printDigit(){
   for(int i = 0; i < 9; ++i)
      cout << times[i] << " ";
   cout << times[9] << endl;
}

int main(){
   for(int i = 0; i < MAXN; ++i) seq[i] = toStr(i);
   
   int cases, N;
   cin >> cases;
   while(cases--){
      for(int i = 0; i < 10; ++i) times[i] = 0;
      cin >> N;
      for(int i = 1; i <= N; ++i){
         for(int j = 0; j < seq[i].size(); ++j){
            times[toInt(seq[i][j])]++;
         }
      }
      printDigit();
   }
   
   return 0;
}
