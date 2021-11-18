#include <bits/stdc++.h>
#define N 100005
#define ll long long int
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

int n,m;
vector<int> v[N];
bool vis[N][2];
int dis[N];
int an[N];
bool cmp(int a,int b){
    return a>b;
}

int ans,cnt;
int ma = 0;
void dfs(int x,int di,int k){
    dis[x] = di;
    vis[x][k] = 1;
    if(di>ans){
        ans = di;
        cnt = x;
    }
    for(int i=0;i<v[x].size();i++){
        int c = v[x][i];
        if(vis[c][k]==0){
            dfs(c,di+1,k);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(an,-1,sizeof(an));
    int cas = 0;
    int index = 0,j = 0;
    for(int i=0;i<n;i++){
        if(vis[i][0]==0){
            index++;
            ans = -1;
            dfs(i,0,0);
            ans = -1;
            dfs(cnt,0,1);
            cas = max(cas,ans);
            ans = (ans+1)>>1;
            an[j++]= ans;
        }
    }
    sort(an,an+j,cmp);
    if(index == 1){
        printf("%d\n",cas);
    }else if(an[0]==an[1]&&an[1]==an[2]){
        printf("%d\n", (an[0]+an[1]+2)>cas?(an[0]+an[1]+2):cas);
    }else{
        printf("%d\n", (an[0]+an[1]+1)>cas?(an[0]+an[1]+1):cas);
    }
    return 0;
}