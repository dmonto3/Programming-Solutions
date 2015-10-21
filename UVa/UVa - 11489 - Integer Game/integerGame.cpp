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

int main(){
   int acum, acum1, acum2, acum3, t, aux;
   string num;
   cin >> t;
   for(int k = 1; k <= t; ++k){
      acum = acum1 = acum2 = acum3 = 0;
      cin >> num;
      for(int i = 0; i < num.size(); ++i){
         aux = toInt(num[i]);
         acum += aux;
         if(aux % 3 == 0){
            acum3++;
         }else if(aux % 3 == 1){
            acum1++;
         }else{
            acum2++;
         }
      }
      cout << "Case " << k << ": ";
      
      if(num.size() == 1){
         cout << "S" << endl;
         continue;
      }
      
      acum %= 3;
      D(acum);
      if(acum == 0){
         if(acum3 % 2 == 0){
            cout << "T" << endl;
         }else{
            cout << "S" << endl;
         }
         continue;
      }
      if(acum == 1){
         if(acum1 == 0){
            cout << "T" << endl;
            continue;
         }
         int n = num.size() - 1;
         
         if(n == acum3){
            if(n % 2 != 0){
               cout << "T" << endl;
            }else{
               cout << "S" << endl;
            }
            continue;
         }else if(n == acum3 + 1){
            if(acum3 % 2 != 0){
               cout << "S" << endl;
            }else{
               cout << "T" << endl;
            }
            continue;
         }else{
            if(acum3 % 2 != 0){
               cout << "T" << endl;
            }else{
               cout << "S" << endl;
            } 
            continue;
         }
      }
      // acum == 2
      if(acum2 == 0){
         cout << "T" << endl;
         continue;
      }
      
      int n = num.size() - 1;
         
      if(n == acum3){
         if(n % 3 != 0){
            cout << "T" << endl;
         }else{
            cout << "S" << endl;
         }
         continue;
      }else if(n == acum3 + 1){
         if(acum3 % 2 != 0){
            cout << "S" << endl;
         }else{
            cout << "T" << endl;
         }
         continue;
      }else{
         if(acum3 % 2 != 0){
            cout << "T" << endl;
         }else{
            cout << "S" << endl;
         } 
         continue;
      }
   }
   return 0;
}
