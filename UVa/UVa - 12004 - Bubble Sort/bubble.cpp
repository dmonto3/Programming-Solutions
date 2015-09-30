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

vector <int> arr;

int findSwaps(int n){
   int count = 0, i, j, temp, b[100];
   
   for(i = 0; i < n; ++i){
      b[i] = arr[i];
   }
   
   for(i = 0; i < n; ++i){
      for(j = 0; j < n - 1; ++j){
         if(b[j] > b[j+1]){
            temp = b[j];
            b[j] = b[j+1];
            b[j+1] = temp;
            
            count++;
         }
      }
   }
   return count;
}


const int MAXN = 100005;
ll ans[MAXN];


int main(){
   /*
   int n; cin >> n;
   for(int i = 0; i < n; ++i)
      arr.push_back(i+1);
   
   int acum = 0;
   while(next_permutation(arr.begin(), arr.end()))
      acum += findSwaps(n);
      
   cout << acum << endl;
   */
   
   ll j = 0LL;
   ans[0] = 0;
   for(int i = 1; i < MAXN; ++i){
      j += i;
      ans[i] = j;
   }
   
   int n, T, cases = 1;
   cin >> T;
   while(T--){
      cin >> n;
      n--;
      cout << "Case " << cases++ << ": ";
      if(ans[n] % 2 ==0)
         cout << ans[n] / 2;
      else
         cout << ans[n] << "/2";
      cout << endl;
   }
   return 0;
}
