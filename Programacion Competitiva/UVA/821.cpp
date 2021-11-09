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


const static int N = 100; // max number of vertices
const static int INF = 1000; // max cost

int main(){    
    int Case = 1;   
    int a, b;
    while (std::cin >> a >> b, !(a == 0 && b == 0)){
        std::vector<std::vector<int>> adj(N + 1, std::vector<int>(N + 1, INF)); // adjacency matrix

        do {
            adj[a][b] = 1; // set cost
        } while (std::cin >> a >> b, !(a == 0 && b == 0)); 

        // Floyd-Warshall 
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]); // set cost 

        int sum = 0, count = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (i != j && adj[i][j] != INF){
                    sum += adj[i][j]; // sum of all pairs
                    ++count; // number of pairs
                }
            
        std::cout << "Case " << Case++ << ": average length between pages = "  << std::setprecision(3) << std::fixed  << (double)sum / count << " clicks"<< std::endl;
    }
    return 0;
}