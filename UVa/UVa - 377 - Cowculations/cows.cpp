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

string reduce(string num1){
   // convert to format number
   string num = "";
   for(int i = 0; i < num1.size(); ++i){
      if(num1[i] == 'V') num += "0";
      if(num1[i] == 'U') num += "1";
      if(num1[i] == 'C') num += "2";
      if(num1[i] == 'D') num += "3";
   }
   
   string res = "";
   int k = 0;
   while(toInt(num[k]) == 0){
      k++;
   }
   for(int i = k; i < num.size(); ++i)
      res += num[i];
   if(!res.size()){
      res += "0";
   }
   return res;
}

string mult10(string num){
   if(num == "0") return "0";
   num += "0";
   return num;
}

string divide10(string num){
   if(num.size() < 2) return "0";
   string res = num.substr(0, num.size() - 1);
   return res;
}

string performOper(string oper, string num1, string num2){
   if(oper == "A") return sumar(num1, num2, 4);
   if(oper == "R") return divide10(num2);
   if(oper == "L") return mult10(num2);
   return num2;
}

int main(){
   int n;
   string num1, num2, expected, oper;
   cin >> n;
   cout << "COWCULATIONS OUTPUT" << endl;
   while(n--){
      cin >> num1 >> num2;
      D(num1);
      num1 = reduce(num1);
      num2 = reduce(num2);
      D(num1);
      
      for(int i = 1; i <= 3; ++i){
         cin >> oper;
         num2 = performOper(oper, num1, num2);
        
        // num2 = reduce(num2);
      }
      
      cin >> expected;
      expected = reduce(expected);
      
      if(expected == num2) cout << "YES";
      else cout << "NO";
      cout << endl;
   }
   cout<< "END OF OUTPUT" <<endl;
   return 0;
}
