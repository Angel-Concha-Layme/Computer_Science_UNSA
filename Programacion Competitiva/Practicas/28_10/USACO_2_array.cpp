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

#define MAX 1000000

int main () {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> difference_array(n + 1);
	for (int i = 0; i < k; i++) { //difference array
		int l, r;
		std::cin >> l >> r;
		l--; // zero-indexed
		r--;
		difference_array[l]++;
		difference_array[r + 1]--; //add position and subtract 1
	}
	int solucion[MAX];
	int tot = 0;
	for (int i = 0; i < n; i++) { // prefix sum array
		tot += difference_array[i];
		solucion[i] = tot;
	}
	std::sort (solucion, solucion + n); // get median
	std::cout << solucion[n / 2] << '\n'; // output the median
}