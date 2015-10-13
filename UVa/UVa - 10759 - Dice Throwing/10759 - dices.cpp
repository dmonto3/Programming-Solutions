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
typedef unsigned long long ull;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXI = 150;
const int MAXJ = 24;

ull dp[MAXI + 5][MAXJ + 5];
ull pot6[MAXJ + 5];

ull gcd(ull a, ull b){
   ull r0, r1, r2;
   r0 = a; r1 = b;
   ull i = 1LL;
   while(r1 != 0){
      r2 = r0 % r1;
      i++;
      r0 = r1;
      r1 = r2;
   }
   return r0;
}

int main(){
   pot6[0] = 1; pot6[1] = 6;
   for(int j = 2; j <= MAXJ; ++j){
      pot6[j] = 6LL * pot6[j-1];
   }
   
   for(int i = 0; i <= 6; ++i){
      dp[i][1] = 1LL;
   }
   for(int i = 7; i <= MAXI; ++i){
      dp[i][1] = 0LL;
   }
   for(int j = 0; j <= MAXJ; ++j){
      dp[0][j] = 0LL;
   }
   
   for(int i = 2; i <= MAXI; ++i){
      for(int j = 2; j <= MAXJ; ++j){
         ull acum = 0LL;
         for(int k = 1; k <= 6; ++k){
            if(i - k >= 1){
               acum += dp[i-k][j-1];
            }
         }
         dp[i][j] = acum;
      }
   }
   
   /*
   for(int i = 1; i <= 10; ++i){
      cout << i << " = ";
      for(int j = 1; j <= 3; ++j)
         cout << dp[i][j] << " ";
      cout << endl;
   }*/
   
   for(int j = 1; j <= MAXJ; ++j){
      for(int i = 2; i <= MAXI; ++i){
         dp[i][j] += dp[i-1][j];
      }
   }
   /*
   for(int i = 1; i <= MAXI; ++i){
      cout << i << " = ";
      for(int j = 1; j <= 3; ++j)
         cout << dp[i][j] << " ";
      cout << endl;
   }*/
   
   int n, x;
   while(cin >> n >> x && (n || x)){
      if(x == 0){
         cout << 1 << endl;
         continue;
      }
      ull total = pot6[n];
      ull ways = total - dp[x-1][n];
      
      if(ways == 0LL){
         cout << 0 << endl;
         continue;
      }
      if(total == ways){
         cout << 1 << endl;
         continue;
      }
      ull mcd = gcd(total, ways);
      total = (int) 1.0*total / mcd;
      ways = (int) 1.0*ways / mcd;
      cout << ways << "/" << total << endl;
   }
   return 0;
}
