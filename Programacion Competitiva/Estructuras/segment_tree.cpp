#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>


//implementation segmet tree
class SegmentTree{
private:
    int n;
    std::vector<int> tree;
    std::vector<int> arr;
public:
    SegmentTree(int n){
        this->n = n;
        this->tree.resize(4*n);
        this->build(0,0,n-1);
    }
    void build(int node, int start, int end){
        if(start == end){
            this->tree[node] = this->arr[start];
            return;
        }
        int mid = (start+end)/2;
        this->build(2*node+1,start,mid);
        this->build(2*node+2,mid+1,end);
        this->tree[node] = this->tree[2*node+1] + this->tree[2*node+2];
    }
    void update(int node, int start, int end, int idx, int val){
        if(start == end){
            this->tree[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if(idx <= mid){
            this->update(2*node+1,start,mid,idx,val);
        }else{
            this->update(2*node+2,mid+1,end,idx,val);
        }
        this->tree[node] = this->tree[2*node+1] + this->tree[2*node+2];
    }
    int query(int node, int start, int end, int l, int r){
        if(start > r || end < l){
            return 0;
        }
        if(start >= l && end <= r){
            return this->tree[node];
        }
        int mid = (start+end)/2;
        int p1 = this->query(2*node+1,start,mid,l,r);
        int p2 = this->query(2*node+2,mid+1,end,l,r);
        return p1+p2;
    }
    void print(){
        for(int i = 0; i < this->tree.size(); i++){
            std::cout << this->tree[i] << " ";
        }
        std::cout << std::endl;
    }
};



int main(){
    int n;
    std::cin >> n;
    SegmentTree st(n);
    for(int i = 0; i < n; i++){
        int val;
        std::cin >> val;
        st.update(0,0,n-1,i,val);
    }
    st.print();
    int q;
    std::cin >> q;
    for(int i = 0; i < q; i++){
        int l,r;
        std::cin >> l >> r;
        std::cout << st.query(0,0,n-1,l-1,r-1) << std::endl;
    }
    
    return 0;
}
