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

typedef long long ll;

const int MAXN = 1000000;

ll cy[MAXN + 5];

ll getCycle(ll n){
	ll acum = 1;
	while(n != 1){
		if(n <= MAXN && cy[n] != -1){
			acum = acum + cy[n];
			acum--;
			break;
		}
		if(n % 2 != 0){
			n = 3LL * n + 1LL;
		}else{
			n /= 2;
		}
		acum++;
	}
	return acum;
}
int main() {
	// your code goes here
	cy[1] = cy[0] = 1;
	for(int i = 2; i <= MAXN; ++i){
		cy[i] = -1LL;
	}
	
	for(int i = 2; i <= MAXN; ++i){
		cy[i] = getCycle(i);
	}
	
	int i, j, ni, nj, aux, maxc;
	while(cin >> i >> j){
		ni = min(i, j);
		nj = max(i, j);
		maxc = 1;
		for(int k = ni; k <= nj; ++k){
			maxc = max(maxc, (int) cy[k]);
		}
		cout << i << " " << j << " " << maxc << endl;
	}
	
	return 0;
}
