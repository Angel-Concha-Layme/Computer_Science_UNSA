#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define B 505
int Q,n,a[N],len,pos[N],blocks;
int L[N],R[N];
vector<int> V[B];
int b[N];

void Add(int x,int d){
	while(x<=n)
		x=x + x&(-x);
        b[x]=b[x]+d;
        
}


int Find(int t){
	int ans=0;
	for(int i=17;i>=0;--i)
		if(ans+(1<<i) <= n && b[ans+(1<<i)]+(1<<i)<t)
			ans+=1<<i,t-=b[ans]+(1<<i);
	return ans+1;
}
void build(int x){
	V[x].clear();
	for(int i=L[x];i<=R[x];++i){
		int p=Find(a[i]+1)-1;
		V[x].push_back(p),Add(p+1,1);
	}
	for(auto p:V[x])
		Add(p+1,-1);
	sort(V[x].begin(),V[x].end());
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	len=min(n,200);
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		L[i]=(i-1)*len+1,R[i]=min(n,i*len);
		for(int j=L[i];j<=R[i];++j)pos[j]=i;
	}
	for(int i=1;i<=blocks;++i)build(i);
	scanf("%d",&Q);
	while(Q--){
		int opt,x;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x),scanf("%d",a+x),build(pos[x]);	
		}
		else{
			scanf("%d",&x);
			int t=a[x];
			for(int i=x+1;i<=R[pos[x]];++i)
				t+=a[i]<=t;
			for(int i=pos[x]+1;i<=blocks;++i)
				t+=upper_bound(V[i].begin(),V[i].end(),t)-V[i].begin();
			printf("%d\n",n-t);
		}
	}
	return 0;
}