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

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) //cout << #x " is " << x << endl

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define ull unsigned long long
typedef pair <ull, int> cell;

const int MAXN = 100005;
vector <ull> nums;
vector <cell> gcds;

ull 
gcd ( ull a, ull b )
{
  ull c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(){
   int t, n;
   ull num, ans;
   cin >> t;
   while(t--){
      ans = 0ULL;
      nums.clear();
      gcds.clear();
      cin >> n;
      for(int i = 0; i < n; ++i){
         cin >> num;
         nums.push_back(num);
      }
      
      // Solution
      cell aux = cell(nums[0], 0);
      gcds.push_back(aux);
      ans = nums[0];
      for(int i = 1; i < n; ++i){
         D(i);
         aux = cell(nums[i], i);
         gcds.push_back(aux);
         
         /*
         for(int k = 0; k < gcds.size(); ++k){
           // D(k);
            cout << gcds[k].first << " " << gcds[k].second << endl;
         }
         */
         
         for(int j = gcds.size() - 1; j >= 1; j--){
            ull x1, x2, newgcd;
            x1 = gcds[j].first;
            x2 = gcds[j-1].first;
            newgcd = gcd(x1, x2);
            
            if(x2 == x1){
               //cout << "hola" << endl;
               gcds.erase(gcds.begin() + j);
               continue;
            }
            if(newgcd == x2){
               /*
               if(x1 * (i - gcds[j].second) > ans){
                  ans = x1 * (i - gcds[j].second);
               }
               if(j != gcds.size() - 1){
                  gcds.erase(gcds.begin() + j);
               }
               */
              // D(i);
               D(ans);
               break;
            }else{
               if(x2 * (i - gcds[j-1].second) > ans){
                  ans = x2 * (i - gcds[j-1].second);
               }
               gcds[j-1].first = newgcd;
               
               //cout << "i = " << i << endl;
               D(i);
            }
            D(ans);
         }
        // D(ans);
      }
      
     // cout << "FIN" << endl;
      D(ans);
      /*
      for(int k = 0; k < gcds.size(); ++k){
           // D(k);
            cout << gcds[k].first << " " << gcds[k].second << endl;
         }
      */
      for(int i = 0; i < gcds.size(); ++i){
         D(ans);
         ull x1;
         x1 = gcds[i].first;
         if(x1 * (n - gcds[i].second) > ans){
            ans = x1 * (n - gcds[i].second);
         }
      }
      cout << ans << endl;
   }
   return 0;
}
