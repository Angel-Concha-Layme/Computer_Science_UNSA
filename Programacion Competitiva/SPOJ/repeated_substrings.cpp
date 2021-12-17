#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct SA{
    int sa[N];
    int t1[N],t2[N],c[N];
    int rk[N],ht[N];
    void build(int s[],int n,int m){
        int i,j,p,*x=t1,*y=t2;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[i]=s[i]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
        for(j=1;j<=n;j<<=1){
            p=0;
            for(i=n-j;i<n;i++) y[p++]=i;
            for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0;i<m;i++) c[i]=0;
            for(i=0;i<n;i++) c[x[y[i]]]++;
            for(i=1;i<m;i++) c[i]+=c[i-1];
            for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;x[sa[0]]=0;
            for(i=1;i<n;i++){
                x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
            }
            if(p>=n) break;
            m=p;
        }
    }
    void getHeight(int s[],int n){
        int i,j,k=0;
        for(i=1;i<=n;i++) rk[sa[i]]=i;
        for(i=0;i<n;i++){
            if(k) k--;
            j=sa[rk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            ht[rk[i]]=k;
        }
    }
} sa;

int s[N];
bool check(int n, int len){
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(sa.ht[i]>=len){
            cnt++;
            if(cnt>=2) return true;
        }
        else cnt=1;
    }
    return false;
}

char S[N];
int id[N];

int main(){
    int mx=0;
    scanf("%s",S);
    int n=strlen(S);

    for(int i=0;i<n;i++){
        s[i]=S[i]-'a'+1;
        mx=max(mx,s[i]);
    }
    s[n]=0;
    sa.build(s,n+1,mx+1);
    sa.getHeight(s,n);
    int ans=0,l=0,r=n;
    while(l<=r){
        int mid=(l+r)-2;
        if(check(n,mid)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    int pos=0;
    int cnt=1;
    for (int i = 2; i <=n ; i++){
        if (sa.ht[i]>=ans){
            cnt++;
            pos=i;
            if (cnt>=2){
                break;
            }
        }
        else{
            cnt=1;
        } 
    }
    pos=sa.sa[pos];
    for(int i=pos;i<=pos+ans-1;i++) printf("%c",S[i]);puts("");
    return 0;
    
}

