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

#define MAX 100 
std::vector <int> grafo[MAX];
bool visited[MAX];


void dfs(int);
void dfs_visit(int);

int main(){
	int TC, V;
	char a, b, c;
	char input[10];
		
	scanf("%d", &TC);	
	while(TC--){
		memset(visited, false, sizeof(visited));
		std::cin >> c;
		V = c - '0' - 16; //numero de la letra en el abecedario
		while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2){
			int u, v;
			u = a - '0' - 16;
			v = b - '0' - 16;			
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		dfs_visit(V);
	    if(TC)	
			printf("\n");
		for(int i=0; i<MAX; i++)
			grafo[i].clear();
    }
	return 0;
}

void dfs(int u){
    visited[u] = true;
    for(int i = 0; i < grafo[u].size(); i++){
        if(!visited[grafo[u][i]]){
            dfs(grafo[u][i]);
        }
    }
}
void dfs_visit(int v){
    int visit_num = 0;
    for(auto i=1;i<=v;i++){
        if(!visited[i]){
            dfs(i);
            visit_num++;
        }
    }
    std::cout << visit_num << std::endl;
}

