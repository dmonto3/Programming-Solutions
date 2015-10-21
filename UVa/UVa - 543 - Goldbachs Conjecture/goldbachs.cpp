//SOLUTION 543 - Goldbachs Conjecture

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
#define D(x) cout << #x " is " << x << endl

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


const int SIZE = 1000005;
//criba[i] = false si i es primo
bool criba[SIZE + 1];
vector <int> numerosOrdenados;

void buildCriba(){
   memset(criba, false, sizeof(criba));
   int k = 2;
   
   criba[0] = criba[1] = true;
   for (int i=4; i <= SIZE; i+=2){
      criba[i] = true;
      k++;
   }

   for(int i=3; i*i <= SIZE; i+=2){
      if(!criba[i]){
         for (int j = i*i; j <= SIZE; j += i){
            criba[j] = true;
         }
      }
   }
}

int main(){
   buildCriba();
   for(int i = 3; i < SIZE; ++i){
      if(!criba[i]){
         numerosOrdenados.push_back(i);
      }
   }
   
   reverse(numerosOrdenados.begin(), numerosOrdenados.end());
   
   int n;
   while(cin >> n && n){
      for(int i = 0; i < numerosOrdenados.size(); ++i){
         if(numerosOrdenados[i] < n){
            if(!criba[n - numerosOrdenados[i]]){
               cout << n << " = " << min(numerosOrdenados[i], n - numerosOrdenados[i]);
               cout << " + " << max(numerosOrdenados[i], n - numerosOrdenados[i]) << endl;
               break;
            }
         }
      }
   }
   
   return 0;
}
