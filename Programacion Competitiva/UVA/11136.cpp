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


int n, x, k; 
long long sum;
std::multiset<int> bills; 
int main() {
    while(std::cin >> n, n){
		sum = 0;
		bills.clear();
		for(int nn=0; nn<n; nn++) {
			std::cin >> k;
			for(int i=0; i<k; i++) {
				std::cin >> x;
				bills.insert(x);
			}
			auto hit = bills.end(), lot = bills.begin(); hit--;
			sum += (*hit)-(*lot);
			bills.erase(hit); bills.erase(lot);
	}
	std::cout << sum << '\n';
    }
    return 0;
}