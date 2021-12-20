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
	int X[128], i, j, t, tt;
	long long int a, b;
	char in[30];
	std::cin >> tt;
	for (t = 1; t <= tt; t++){
		std::cin >> in;
		a = b = 1LL;
		for (i = 'A'; i <= 'Z'; i++){
			X[i] = 0;
		}
		for (i = 0; in[i] != '\0'; i++){
			a *= (i + 1);
			b *= (++X[in[i]]);
		}
		std::cout << "Data set " << t << ": " << a / b << std::endl;
	}
	return 0;
}