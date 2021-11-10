#ifndef _NN_H_
#define _NN_H_

class NN{
private:
    int getMinIndex(int start){
        int minLocal = INF;
        int pos = -1;
        for(int i = 0; i < n; ++i){
            if(dist[start][i] < minLocal && !visited[i] && start != i){
                minLocal = dist[start][i];
                pos = i;
            }
        }
        pathLength += dist[start][pos];
        return pos;
    }    
public:
    int n;
    int pathLength;
    bool *visited;
    int visited_all;
    int **dist;
    vector<int> circuit;

    NN(int **G, int V){
        n = V;
        pathLength = 0;
        dist = new int *[n];
        for (size_t i = 0; i < n; i++){
            dist[i] = new int [n];
            for (size_t j = 0; j < n; j++){
                dist[i][j] = G[i][j];
            }
            
        }
        visited = new bool[n];
        for (size_t i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        
        visited_all = 0;        
    }
    ~NN(){
        for (size_t i = 0; i < n; i++)
        {
            delete [] dist[i];
        }
        delete [] dist;
        delete [] visited;
    } 

    void solve(int startNode){
        int start = startNode;
        visited[start] = true;
        visited_all += 1;
        //cout << "vecino " << start << " visitado.\n";
        circuit.push_back(start);

        while (visited_all != n)
        {
            int pos = getMinIndex(start);
            visited[pos] = true;
            visited_all += 1;
            //cout << "vecino " << pos << " visitado.\n";
            circuit.push_back(pos);
            start = pos;
        }
        pathLength += dist[start][startNode];
        //cout << "vecino " << startNode << " visitado" << endl;
        //cout << "Procesado al 100%" << endl;
        circuit.push_back(startNode);
    } 
    void printResult(){
        //cout << "Peso total del circuito en bruto:  " << pathLength << endl;
    }
    vector<int> getCircuit(){
        return circuit;
    }
};

#endif