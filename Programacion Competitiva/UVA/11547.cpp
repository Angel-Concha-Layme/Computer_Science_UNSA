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
int main(){
    int cases;
    std::cin>>cases;
    while (cases--){
        int n_temporal;
        std::cin>>n_temporal;
        std::cout << abs((((((n_temporal * 63) + 7492) * 5) - 498) / 10) % 10) << std::endl; // [* 567 / 9] - [* 235 / 47]
    }
}