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

int main() {
	int n, i;
	while(std::cin >> n && n) {
		std::cout << n << " : ";
		int ans = 0;
		for(i = 2; i <= sqrt(n); i++) {
			if(n%i == 0)
				ans++;
			while(n%i == 0) {
				n /= i;
			}
		} 
		if(n != 1)	ans++;
		std::cout << ans << std::endl;
	}
    return 0;
}