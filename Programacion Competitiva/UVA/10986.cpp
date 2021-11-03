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


typedef std::pair<int, int> ii; //ii == ipair == pair<int,int>
const int INF = 1e9; // 1,000,000,000

int main() { 
    int TC, case_n = 0; 
    std::cin >> TC; 
    while (TC--) { 
        int n, m, s, t; 
        std::cin >> n >> m >> s >> t; 
        
        std::vector<std::vector<ii>> AL(n); // Adjacency List

        int u, v, w;
        while (m--) {
            std::cin >> u >> v >> w;
            AL[u].push_back({v, w});
            AL[v].push_back({u, w});
        }

        std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq; // Priority Queue
        pq.push({s, 0});
        std::vector<int> dist(n, INF);
        dist[s] = 0;
        while (!pq.empty()) { // BFS
            ii u = pq.top();
            pq.pop();   

            if (dist[u.first] == u.second) {    
                for (auto&& v : AL[u.first]) {
                    if (dist[u.first] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u.first] + v.second;
                        pq.push({v.first, dist[v.first]});  
                    }   
                }
            }
        } 

        std::cout << "Case #" << ++case_n << ": ";
        if (dist[t] == INF) std::cout << "unreachable\n";
        else std::cout << dist[t] << std::endl;
    }
}