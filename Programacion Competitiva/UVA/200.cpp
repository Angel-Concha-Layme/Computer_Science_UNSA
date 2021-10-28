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


const int MAX = 26; //letters 

std::vector<int> g[MAX];
int degreeOfIn[MAX], visited[MAX];

int main(){
    std::string word;
    std::vector<std::string> words;

    while (std::getline(std::cin, word)) {
        if (word != "#") {
            words.push_back(word);
            continue;
        }

        for (int u = 0; u < MAX; u++){
            g[u].clear();}
        
        memset(degreeOfIn, 0, sizeof(degreeOfIn));
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < words.size() - 1; i++)
            for (int j = 0; j < std::min(words[i].length(), words[i + 1].length()); j++){
                int u = words[i][j] - 'A', v = words[i + 1][j] - 'A';
                visited[u] = visited[v] = 1;
                if (u != v){
                    g[u].push_back(v);
                    degreeOfIn[v]++;
                    break;
                }
            }

        std::queue<int> q;
        for (int u = 0; u < MAX; u++){
            if (visited[u] && degreeOfIn[u] == 0){
                q.push(u);
            }
        }

        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto v : g[u])
                if (--degreeOfIn[v] == 0)
                    q.push(v);
            std::cout << (char)('A' + u);
        }
        std::cout << '\n';

        words.clear();
    }

    return 0;
}