#include<stdio.h>
#include<string.h>
#include<algorithm>

#define MAX 100000
int a[MAX]={0};

int main(){
    int n,k,t;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a[t]++;    
        a [t + 1000] --; 
    }
    int sum=0,ans=0;
    for(int i=0;i<MAX;i++){
        sum+=a[i];
        ans = std::max (sum, ans); // maximum number of runs at the same time
    }
    printf("%d\n",ans%k==0?(ans/k):(ans/k+1));
    return 0;
}

