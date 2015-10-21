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

typedef unsigned long long ull;

const int MAXN = 1000;

string rays[MAXN + 5];

string sumar(string a, string b, int base){
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   string s;
   if(a.size() < b.size()){
      s = a; a = b; b = s;
   }
   int m = a.size(); int n = b.size();
   
   string res = "";
   int aux = 0;
   int x, y;
   for(int i = 0; i < n; ++i){
      x = toInt(a[i]); y = toInt(b[i]);
      x += y + aux;
      res += toStr(x % base);
      aux = x / base;
   }
   for(int i = n; i < m; ++i){
      x = toInt(a[i]);
      x += aux;
      res += toStr(x % base);
      aux = x / base;
   }
   while(aux != 0){
      res += toStr(aux % base);
      aux /= base;
   }
   reverse(res.begin(), res.end());
   return res;
}

int main(){
   rays[0] = "1";
   rays[1] = "2";
   
   for(int i = 2; i <= MAXN; ++i){
      rays[i] = sumar(rays[i-1], rays[i-2], 10);
   }
   int n;
   while(cin >> n){
      cout << rays[n] << endl;
   }
   return 0;
}
