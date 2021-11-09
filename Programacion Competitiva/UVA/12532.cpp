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

int n,q,x[100005],tree[500000],a,b;
char c;

void makeTree(int, int, int);
void initialize_makeTree();
int query(int, int, int, int, int) ;
int initialize_query(int, int); 
void update(int, int, int, int, int);
void initialize_update(int, int);


int main() {
   while(std::cin >> n >> q) {
      for(int i = 0; i < n; ++i) {
         std::cin >> x[i];
         if(x[i]>0) x[i] = 1;
         if(x[i]<0) x[i] = -1;
      }
      initialize_makeTree();
      while(q--) {
         std::cin >> c >> a >> b;
         if(c == 'C') {
            if(b > 0) b = 1;
            if(b < 0) b = -1;
            initialize_update(--a, b);
            x[a] = b;
         }
		 else {
			switch(initialize_query(--a,--b)){
				case -1: std::cout.put('-'); break;
				case 1: std::cout.put('+'); break;
				case 0: std::cout.put('0');
			}
         }
      }
      std::cout << '\n';
   }
   return 0;
}


void makeTree(int node, int lo, int hi) {
	if(lo == hi){
		tree[node] = x[lo];
		return;
	}
	int mid = (lo+hi)/2;
	makeTree(2*node, lo, mid);
	makeTree(2*node + 1, mid + 1, hi);
	tree[node] = tree[2*node] * tree[2*node+1];
}
void initialize_makeTree(){
	int n4=n*4;
	for(int i=0;i<=n4;i++) tree[i]=1;
	makeTree(1,0,n-1);
}
int query(int node, int lo, int hi, int i, int j) {
	if(hi < i || lo > j) return 1;
	if(lo >= i && hi <= j) return tree[node];
	int mid = (lo + hi) / 2;
	return query(2*node, lo, mid, i, j) * query(2*node+1, mid + 1, hi, i, j);
}
int initialize_query(int i, int j) {
	return query(1, 0, n - 1, i, j);
} 
void update(int node, int ind, int val, int lo, int hi) {
	if(ind < lo || ind > hi) return;
	if(lo == hi) {
		tree[node] = val;
		return;
	}
	int mid = (lo + hi) / 2;
	update(2*node, ind, val, lo, mid);
	update(2*node + 1, ind, val, mid + 1, hi);
	tree[node] = tree[2*node] * tree[2*node+1];
}
void initialize_update(int ind, int val) {
	update(1, ind, val, 0, n - 1);
}