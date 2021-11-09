#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>

const int N=501;
int dp[N][6];
int cube[N][6];
std::string mark[6]={"front","back","left","right","top","bottom"};
int inde[N][N][2];

void path(int x,int y,int hei);
int n,ans;

int main(){
    int lastFace,lastIndex,posx,posy,t=1;
    int flag=0;
    while(std::cin>>n,n){
        memset(dp,0,sizeof(dp));
        posx=posy=ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<6;j++)
            std::cin>>cube[i][j];
        }
        for(int i=0;i<6;i++){
            dp[n][i]=1;
        }
        
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<6;j++){
                dp[i][j]=1;
                for(int k=i+1;k<=n;k++){
                    for(int m=0;m<6;m++){
                        if(cube[i][(j+1)%2?j+1:j-1]==cube[k][m]&&dp[i][j]<dp[k][m]+1){
                            dp[i][j]=dp[k][m]+1;
                            lastIndex=k;
                            lastFace=m;
                        }
                    }
                }
                inde[i][j][0]=lastIndex;
                inde[i][j][1]=lastFace;
                if(ans<dp[i][j]){
                    ans=dp[i][j];
                    posx=i;
                    posy=j;
                }
            }
        }

        if(flag++)
        std::cout<<std::endl;
        std::cout<<"Case #"<<t++<<std::endl;
        std::cout<<ans<<std::endl;
        path(posx,posy,ans);
    }
    return 0;
}

void path(int x,int y,int hei){
    if(hei==0)
    return ;
    std::cout<<x<<" "<<mark[y]<<std::endl;
    path(inde[x][y][0],inde[x][y][1],hei-1);
}
