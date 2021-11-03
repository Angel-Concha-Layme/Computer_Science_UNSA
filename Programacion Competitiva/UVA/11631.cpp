#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>


const int MAXV = 200000;
std::vector<std::pair<int, std::pair<int, int> > > g; // <destino, <peso, origen> >
int parent[MAXV]; // parent[i] es el padre de i
 
void reset(){
	for(int i = 0; i < MAXV; ++i){ 
		parent[i] = i; 
	}
	g.clear(); 
}
 
int find(int v){
	if(parent[v] == v) return v;
	return find(parent[v]); 
}
 
void onion(int v, int u){
	parent[find(u)] = find(v); // uniendo v con u
}
 
int kruskal(){ // retorna el peso del arbol
	std::sort(g.begin(), g.end());
	int price = 0;
	for(auto &a: g){
		int weight = a.first;
		std::pair<int, int> ver = a.second;
		if(find(ver.first) != find(ver.second)){
			price += weight;
			onion(ver.first, ver.second);
		}
	}
	return price;
}
 
int main() {
	std::cin.tie(NULL);
	int m, n;
	while(std::cin >> m >> n && (m || n)){
		int price = 0;
		reset();
		for(int i = 0; i < n; ++i){
			int x, y, z;
			std::cin >> x >> y >> z;
			g.push_back({z,{x, y}});
			price += z;
		}
		std::cout << price - kruskal() << "\n";
	}
	return 0;
}