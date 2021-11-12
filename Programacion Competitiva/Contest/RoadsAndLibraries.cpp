#include <iostream>
#include <vector>
#include <queue>

int main(){
    int q;
    std::cin >> q;
    for(auto k = 0; k < q; k++){
        int n;
        int m;
        int cl;
        int cr; 
        std::cin >> n >> m >> cl >> cr;
        std::vector <std::vector<int>> g;
        std::vector <bool> visit;
        g.resize(n);
        visit.resize(n, false);
        for(auto j = 0; j < m; j++){
            int u;
            int v;
            std::cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long total = 0;
        for (int k = 0; k < n; k++) {
            if (!visit[k]) {
                long long cnt = 0;
                std::queue <int> Q; 
                Q.push(k);
                while (!Q.empty()) {
                    int actual = Q.front();
                    Q.pop();
                    if (!visit[actual]) {
                        cnt++;
                        visit[actual] = true;
                    }
                    for (int j = 0; j < g[actual].size(); j++) {
                        if (!visit[g[actual][j]]) {
                            Q.push(g[actual][j]);
                        }
                    }
                }
                total += std::min((cnt-1)*cr+cl, cnt*cl); //cnt-1 porque el ultimo no tiene vecino 
            }
        }
        std::cout << total << std::endl;
    }
    return 0;
}