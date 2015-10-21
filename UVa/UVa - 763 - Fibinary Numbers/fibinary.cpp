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

typedef unsigned long long ull;

const int MAXN = 105;

double rays2[MAXN];

string rays[MAXN + 5];

string restar(string a, string b, int base){
   if(a == b) return "0";
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   string res = "";
   int x, y;
   for(int i = 0; i < b.size(); ++i){
      D(i);
      x = toInt(a[i]); y = toInt(b[i]);
      if(x >= y){
         res += toStr(x - y);
      }else{
         res += toStr(base - y + x);
         for(int j = i + 1; j < a.size() ; ++j){
            D(j);
            if(a[j] == '0'){
               a[j] = toStr(base - 1)[0];
            }else{
               D(a);
               a[j] = toStr(toInt(a[j]) - 1)[0];
               D(a);
               break;
            }
         }  
      }
   }
   D(res);
   D(a);
   int n = res.size();
   for(int i = n; i < a.size(); ++i){
      res += a[i];
   }
  // cout << "hola";
   n = 0;
   for(int i = res.size() - 1; i >= 0; i--){
      if(res[i] != '0'){
         n = i + 1;
         break;
      }
   }
   //cout << "hola";
   res = res.substr(0, n);
   reverse(res.begin(), res.end());
   D(res);
   return res;
}


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

string fibToDec(string a){
   string ans = "0";
   int n = a.size();
   for(int i = 0; i < a.size(); ++i){
      if(a[i] == '1'){
         ans = sumar(ans, rays[n-1-i], 10);
      }
   }
   return ans;
}

bool menorIgual(string s1, string s2){
   if(s1 == "0") return true;
   if(s1.size() < s2.size()) return true;
   if(s1.size() > s2.size()) return false;
   for(int i = 0; i < s1.size(); ++i){
      if(s1[i] < s2[i]) return true;
      if(s1[i] > s2[i]) return false;
   }
   return true;
}

int calcSize(string decimal){
   for(int i = 0; i < MAXN; ++i){
      if(menorIgual(decimal, rays[i])){
         if(decimal == rays[i]){
            return i + 1;
         }else{
            return i;
         }
      }
   }
   return MAXN;
}

string decToFib(string s1){
   if(s1 == "0") return s1;
   int n = calcSize(s1);
   string ans = "1";
   for(int i = 2; i <= n; ++i){
      ans += "0";
   }
   s1 = restar(s1, rays[n-1], 10);
   for(int i = n - 3; i >= 0; i--){
      if(menorIgual(rays[i], s1)){
         ans[n - 1 - i] = '1';
         s1 = restar(s1, rays[i], 10);
         if("0" == s1){
            break;
         }
         i--;
      }
   }
   return ans;
}

int main(){
   rays[0] = "1";
   rays[1] = "2";
   
   for(int i = 2; i <= MAXN; ++i){
      rays[i] = sumar(rays[i-1], rays[i-2], 10);
   }
   
   
   
   rays2[0] = 1.0;
   rays2[1] = 2.0;
   
   /*
   for(int i = 2; i <= MAXN; ++i){
      rays2[i] = rays2[i-1] + rays2[i-2];
   }
   
   int n;
   while(cin >> n)
      cout << rays2[n] << ", " << rays[n] << endl;
   */
   
   
   string s1, s2, suma;
   int acum = 0;
   while(cin >> s1 >> s2){
      if(acum != 0){
         cout << endl;
      }
      s1 = fibToDec(s1);
      s2 = fibToDec(s2);
      suma = sumar(s1, s2, 10);
    //  cout << "suma = " << suma;
      suma = decToFib(suma);
      cout << suma << endl;
      acum++;
   }
   return 0;
}
