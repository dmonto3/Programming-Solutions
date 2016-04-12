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

const int MAXN = 10005;

vector <int> g[MAXN];    // El grafo
vector <int> grev[MAXN]; // El grafo con las aristas reversadas
vector <int> topo_sort;  // El "ordenamiento topologico" del grafo
int owed[MAXN];
int scc[MAXN];   // La componente a la que pertenece cada nodo
bool seen[MAXN]; // El arreglo de visitado para el primer DFS

// DFS donde se halla el ordenamiento topológico
void dfs1(int u){ 
   seen[u] = true;
   for (int i = 0; i < g[u].size(); ++i){
      int v = g[u][i];
      if (!seen[v]) dfs1(v);
   }
   topo_sort.push_back(u);
}
// DFS donde se hallan las componentes
void dfs2(int u, int comp){ 
   scc[u] = comp;
   for (int i = 0; i < grev[u].size(); ++i){
      int v = grev[u][i];
      if (scc[v] == -1) dfs2(v, comp);
   }
}

// Halla las componentes fuertemente conexas del grafo usando
// el algoritmo de Kosaraju. Retorna la cantidad de componentes
int find_scc(int n){ // n = número de nodos
   // Crear el grafo reversado
   for (int u = 0; u < n; ++u){
      for (int i = 0; i < g[u].size(); ++i){
         int v = g[u][i];
         grev[v].push_back(u);
      }
   }

   // Llamar el primer dfs
   for (int i = 0; i < n; ++i){
      if (!seen[i]) dfs1(i);
   }
   reverse(topo_sort.begin(), topo_sort.end());

   // Llamar el segundo dfs
   int comp = 0;
   for (int i = 0; i < n; ++i){
      int u = topo_sort[i];
      if (scc[u] == -1) dfs2(u, comp++);
   }
   return comp;
}

long long wComp(int idx, int n){
	long long sum = 0LL;
	for(int i = 0; i < n; ++i){
		if(scc[i] == idx){
			sum += (long long) owed[i];
		}
	}
	return sum;
}

bool isPos(int ncomp, int n){
	for(int i = 0; i < ncomp; ++i){
		if(wComp(i, n) != 0LL){
			return false;
		}
	}
	return true;
}

int main() {
	int cases, n, m, aux, aux2, ncomp;
	cin >> cases;
	while(cases--){
		cin >> n >> m;
		topo_sort.clear();
		for(int i = 0; i < n; ++i){
			g[i].clear();
			grev[i].clear();
			scc[i] = -1;
			seen[i] = false;
			owed[i] = 0;
		}
		for(int i = 1; i <= n; ++i){
			cin >> aux; owed[i-1] = aux;
		}
		for(int i = 1; i <= m; ++i){
			cin >> aux >> aux2;
			g[aux].push_back(aux2);
			g[aux2].push_back(aux);
		}
		ncomp = find_scc(n);
		if(isPos(ncomp, n)){
			cout << "POSSIBLE" << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
