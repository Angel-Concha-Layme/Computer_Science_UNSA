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


#define ll long long

int main() {
	ll n;
	while (1) {
		std::cin >> n;

		if (n == 0){
			break;
        }

		std::cout<<n<<" = ";
		std::vector<int> res;

		if (n < 0){
			n *= -1;
			res.push_back(-1);
		}

		while(n%2==0){
			res.push_back(2);
			n /=2;
		}

		for(ll i = 3; i * i <= n; i += 2){
			while(n % i == 0){
			    res.push_back(i);
				n /= i;
			}
		}

		if(n > 1){
			res.push_back(n);
        }

		int size = res.size();

		for(int i=0; i<size; i++){
			std::cout<<res[i];
			if(i+1 < size){
				std::cout<<" x ";
		    }
        }
		std::cout << std::endl;
	}
	return 0;
}