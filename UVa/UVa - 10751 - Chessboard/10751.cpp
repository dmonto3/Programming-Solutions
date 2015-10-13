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

typedef pair <int, int> cell;

vector <cell> board;
vector <cell> path;

bool areAdjacent(cell p1, cell p2){
   if(abs(p1.first - p2.first) > 1) return false;
   if(abs(p1.second - p2.second) > 1) return false;
   return true;
}

bool isDiagonal(cell p1, cell p2){
   if(abs(p1.first - p2.first) != 1) return false;
   if(abs(p1.second - p2.second) != 1) return false;
   return true;
}

double distanceCell(cell p1, cell p2){
   int aux = abs(p1.first - p2.first);
   int aux2 = abs(p1.second - p2.second);
   
   return sqrt(aux * aux + aux2 * aux2);
}

bool adjacentPath(){
   for(int i = 0; i < path.size() - 1; ++i){
      if(!areAdjacent(path[i], path[i+1])){
         return false;
      }
   }
   return true;
}

bool noInterception(){
   if(path.size() <= 4) return true;
   for(int i = 0; i < path.size() - 3; ++i){
      if(isDiagonal(path[i], path[i+1]) && isDiagonal(path[i+2], path[i+3])){
         return false;
      }
   }
   
   int aux = path.size() - 2;
   
   if(isDiagonal(path[1], path[2]) && isDiagonal(path[aux], path[aux+1])){
      return false;
   }
   
   if(isDiagonal(path[1], path[0]) && isDiagonal(path[aux-1], path[aux])){
      return false;
   }
   return true;
}

void buildPath(){
   path.clear();
   for(int i = 0; i < board.size(); ++i){
      path.push_back(board[i]);
   }
   path.push_back(path[0]);
}

bool rightPath(){
   if(!adjacentPath()) return false;
   if(!noInterception()) return false;
   
   return true;
}

double pathDistance(){
   double acum = 0.0;
   for(int i = 0; i < path.size() - 1; ++i){
      acum = acum + distanceCell(path[i], path[i+1]);
   }
   return acum;
}

void printV(){
   for(int i = 0; i < path.size(); ++i){
      cout << path[i].first << " " << path[i].second << endl;
   }
   cout << endl;
}

int main(){
   int cases, n;
   double res;
   cin >> cases;
   
   while(cases--){
      cin >> n;
      res = 0.0;
      if(n > 1){
         res = (n - 2) * (n - 2) * sqrt(2);
         res = res + n * n - (n - 2) * (n - 2);
         printf("%.3lf\n", res);
      }else
         cout << 0.000;
      cout << endl;
   }
   return 0;
}
