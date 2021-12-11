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


#define int long long
const int mxN = 1e5+5; //10^5 -> max number of nodes
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN]; // suffix array, position array, temporary array, lcp array
int gap, N; // gap, number of suffixes
std::string S; // input string

bool comp(int, int);
void suffix();
void build_lcp();
void push(int);
void update(int, int, int, int, int, int);
int assign(int, int, int, int, int, int);
int sum(int, int, int, int, int);

signed main(){
    std::cin >> S;
    N = S.size();
    suffix();
    build_lcp();
    int k; std::cin>>k;

    k = N*(N+1)/2 - k + 1;
    int K = 1<<(int) ceil(log2(N+1));
    int cur = 0;
    for (int i = N-1; i >= 0; i--) {
        update(1, 1, N-sa[i], 1, 0, K-1);
        int prev = (i ? lcp[i-1] : 0);
        int l = prev+1, r = N-sa[i];
        int ans = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (cur + sum(m, N-sa[i], 1, 0, K-1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) {
            return std::cout << S.substr(sa[i], ans), 0;
        }
        cur += sum(prev+1, N-sa[i], 1, 0, K-1);
        assign(0, prev+1, N-sa[i], 1, 0, K-1);
    }
}




bool comp(int x, int y) {
    if ( pos[x] != pos[y] )
        return pos[x] < pos[y]; // pos is the position array
    x += gap; // x is not in the first part
    y += gap; // y is not in the first part
    return (x < N && y < N) ? pos[x] < pos[y] : x > y; 
}

void suffix() {
    for ( int i = 0; i < N; i++ )
        sa[i] = i, pos[i] = S[i]; // pos[i] = S[i] - 'a';

    for ( gap = 1;; gap <<= 1 ) {
        std::sort(sa, sa+N, comp); // sort suffixes according to their first gap characters
        for ( int i = 0; i < N-1; i++ )
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]); // number of suffixes with first gap characters equal to current suffix
        for ( int i = 0; i < N; i++ )
            pos[sa[i]] = tmp[i]; // update position array
        if ( tmp[N - 1] == N - 1 )
            break;
    }
}

void build_lcp() {
    for ( int i = 0, k = 0; i < N; i++ ) // k is the current index in lcp[]
      if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while ( S[i + k] == S[j + k] ) // k is the length of the common prefix
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

std::pair<int,int> seg[mxN*10]; // segment tree
int mark[mxN*10]; // mark array

void push( int k ) { // k = 2^i
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].first = seg[2*k + 1].first= seg[k].first/2; // update the first value
        seg[2*k].second = seg[2*k + 1].second= 0; // update the second value
        mark[2*k] = mark[2*k + 1] = 1; // mark the children as to be updated
    }
}

void update(int v, int a, int b, int k, int x, int y) {
    if ( b < x || a > y ) return; // current segment is not within range [x,y]
    if ( a<=x && b>=y ) {
        seg[k].second += v; // add the value to the segment
        return;
    }
    int h = std::min(b,y) - std::max(a,x) + 1;
    push(k); // push the segment
    seg[k].first += h*v; // add the value to the segment
    int d = (x+y)/2; // divide the segment into two halves
    update(v, a, b, 2*k, x, d); // update the left child
    update(v, a, b, 2*k + 1, d + 1, y); // update the right child
}
int assign(int v, int a, int b, int k, int x, int y) {
    if ( b < x || a > y )
      return seg[k].first+ (y - x + 1)*seg[k].second; // current segment is not within range [x,y]
    if ( a <= x && b >= y ) {
        seg[k].first = (y-x+1)*v; // add the value to the segment
        seg[k].second = 0; // reset the second value
        mark[k] = 1; // mark the segment as to be updated
        return seg[k].first; // add the value to the segment
    }
    push(k);
    int d = (x+y)/2;
    seg[2*k].second += seg[k].second,  seg[2*k + 1].second+= seg[k].second; // add the value to the children
    seg[k].second = 0; // reset the value of the current segment
    seg[k].first = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y); // assign the value to the children
    return seg[k].first; // return the value of the current segment

}
int sum(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].first + (y-x+1)*seg[k].second; // current segment is within range [x,y]
    }
    push(k);
    seg[k].first += (y-x+1)*seg[k].second;  // add the value to the segment
    seg[2*k].second += seg[k].second, seg[2*k + 1].second += seg[k].second; // add the value to the children
    seg[k].second = 0; // reset the value of the segment
    int d = (x+y)/2; // divide the range
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y); // recurse on the children
}