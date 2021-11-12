#include <bits/stdc++.h>

int acumulado[500005];
std::vector< std::vector<std::pair<int, int>> > adjacency_matrix;

void Dijkstra(int s, int n){
    for(int i = 0; i<n; i++)
        acumulado[i] = 2147483647;  // 2147483647 es el valor maximo de int
    acumulado[s] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > p_queue;
    p_queue.push( std::pair<int, int>(acumulado[s], s) );
    std::pair<int, int> p;
    int t, u;
    while(!p_queue.empty()){
        p = p_queue.top();
        p_queue.pop();
        t = p.first;
        u = p.second;
        if(t > acumulado[u] ) 
            continue;
        for(int i = 0; i<adjacency_matrix[u].size(); i++){
            adjacency_matrix[u][i].second = std::min(adjacency_matrix[u][i].second, adjacency_matrix[u][i].second - acumulado[u]);
            adjacency_matrix[u][i].second = std::max(adjacency_matrix[u][i].second, 0);
            if(acumulado[adjacency_matrix[u][i].first] > acumulado[u] + adjacency_matrix[u][i].second){
                acumulado[adjacency_matrix[u][i].first] = acumulado[u] + adjacency_matrix[u][i].second;
                p_queue.push( std::pair<int, int>(acumulado[adjacency_matrix[u][i].first], adjacency_matrix[u][i].first) );
            }
            
        }
    }
}

int main(){
    int g_nodes, g_edges;
    std::cin >> g_nodes >> g_edges;

    int g_from, g_to, g_weight;
    adjacency_matrix.assign(g_nodes, std::vector<std::pair<int,int>>(0));

    for (int k = 0; k < g_edges; k++){
        std::cin >> g_from >> g_to >> g_weight;
        g_from--;
        g_to--;
        adjacency_matrix[g_from].push_back( std::pair<int, int>(g_to, g_weight) );
        adjacency_matrix[g_to].push_back( std::pair<int, int>(g_from, g_weight) );
    }
    Dijkstra(0, g_nodes);
    if(acumulado[g_nodes-1] != 2147483647) {
        if (acumulado[g_nodes-1] < 0)
            std::cout << 0;
        else
            std::cout << acumulado[g_nodes-1];
    }
    else
        std::cout << "NO PATH EXISTS";
    return 0;
}