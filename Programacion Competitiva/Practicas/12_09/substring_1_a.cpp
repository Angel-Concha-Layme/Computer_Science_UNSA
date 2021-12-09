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



const int mxN = 1e5+5; // Max number of nodes
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN]; // suffix array, LCP array, temporary array, temporary array
int gap, N; // number of nodes
std::string input; 
 
bool comp(int x, int y) {
    if (pos[x] != pos[y]){ 
        return pos[x] < pos[y];
    }
    x += gap; 
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y; // if x or y is out of bounds, return x > y
}
 
void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = input[i];
 
    for (gap = 1;; gap <<= 1) {
        std::sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while (input[i + k] == input[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}
 
int main(){
    std::cin>>input; N = input.size();
    suffix();
    build_lcp();
    int k; std::cin>>k;
    int prev = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur + (N-sa[i]) - prev >= k) {
            int j = prev; // j is the first index of the substring
            std::string ans = input.substr(sa[i], j);
            while (cur < k) {
                ans += input[sa[i]+j]; 
                cur++;
                j++;
            }
            return std::cout << ans, 0;
        }
        cur += (N-sa[i]) - prev; 
        prev = lcp[i]; 
    }
}

