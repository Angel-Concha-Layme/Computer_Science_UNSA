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
#include <complex>
#include <utility>

using namespace std;

#define F first 
#define S second
 
bool cmp(pair<double, double>, pair<double, double>);
 
int main() {
    int n;
    double p, r; // position, radius
    double l, w, dx; 
     
    while (cin >> n >> l >> w) {
        w /= 2.0; 
        vector<pair<double, double>> v; 
        for (int i=0; i<n; i++) {
            cin >> p >> r;
            if (r > w){ 
                dx = sqrt(r*r - w*w);  // distance to the edge
                v.push_back({p-dx, p+dx}); 
                //std::cout<<"dx: "<<dx<<"\n";
                //std::cout<<"v: "<<p-dx<<" - "<<p+dx<<"\n";
            }
        }
        sort(v.begin(), v.end(), cmp);
         
        int ans = 0;
        double right = 0.0; 
        for (int i = 0; i < v.size(); i++){
            if (v[i].F > right) break; 
            for (int j = i+1; j < v.size() && v[j].F <= right; j++){ 
                if (v[j].S > v[i].S){ 
                    i = j;
                }
            }
            ans++;
            right = v[i].S;
            if (right >= l) break;
        }
         
        if (right >= l) cout << ans << "\n"; // if the last position is in the lawn
        else cout << "-1\n"; // if the last position is not in the lawn
    }
    return 0;
}

bool cmp(pair<double, double> a, pair<double, double> b) {
    if (a.first == b.first)
        return a.second > b.second; // if equal, return the one with the bigger second
    else
        return a.first < b.first; // if not equal, return the one with the smaller first
}