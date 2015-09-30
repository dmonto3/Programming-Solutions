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

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


double L, Ll;

double f(double alfa){
	return 2 * Ll * sin(alfa / 2.0) - alfa * L;
}

double biseccion(){
	double an = 0.0, bn = PI, theta, R;
	double an1, bn1;
	int i = 1;
	while(i < 100 && an - bn != 0.0){
		theta = (an + bn) / 2.0;
		R = L / (2 * sin(theta / 2));
		
		if(R * theta - Ll < 0){
			an = theta;
		}else{
			bn = theta;
		}
		i++;
	}
	return R - R * cos(theta / 2);
}

int
main() {
	double n, C;
	while(cin >> L >> n >> C && L >= 0){
		Ll = (1 + n*C)*L;
		printf("%.3lf\n", biseccion());
	} 
	return 0;
}
