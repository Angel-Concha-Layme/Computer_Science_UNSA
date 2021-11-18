#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
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


using namespace std;
#define MAX 1000000
int stack[MAX];
int s[MAX], e[MAX];

int main(){
    int n, k;
    int pos=0, poe=0, plus=0;
    int i;
    
    cin >> n >> k;
    for(i=0;i<k;i++){
        cin >> s[i] >> e[i];
    }
    sort(s,s+k);
    sort(e, e+k);
    for(i=0;i<n;i++){
        while(i==s[pos]){
            plus++, pos++;
        }
        while(i==e[poe]+1){
            plus--, poe++;
        }
        stack[i]=plus;
    }
    sort(stack, stack+n);
    cout << stack[n/2] << endl;
    return 0;
}

