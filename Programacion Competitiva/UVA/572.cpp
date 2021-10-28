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

using namespace std;

int m,n,cont;
vector<string> v;
string s;
bool visited[100][100];

int adjacent_i[]={1,1,1,-1,-1,-1,0,0};
int adjacent_j[]={1,0,-1,1,0,-1,1,-1};

void fill(int, int);

int main(){
    while(1){
        cin>>m>>n;
        if(m==0) break;  
        v.clear();
        for(int i=0;i<m;i++){
            cin>>s;
            v.push_back(s);
        }
        
        cont=0;
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    visited[i][j]=1;
                    if(v[i][j]=='@'){
                        cont++;
                        fill(i,j);
                    }
                }
            }
        }
        cout<<cont<<endl;
    }
}

void fill(int a, int b){
    visited[a][b]=1;    
    int I,J;
    
    for(int i=0;i<8;i++){
        I=a+adjacent_i[i]; 
        J=b+adjacent_j[i]; 
        if(I>=0 && I<m && J>=0 && J<n && !visited[I][J]){
            visited[I][J]=1;
            if(v[I][J]=='@') fill(I,J);
        }
    }
}
