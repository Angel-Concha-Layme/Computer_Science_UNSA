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



struct SuffixArray {
	std::vector<int> sa, lcp;
	SuffixArray(std::string& s, int lim=256) {
		int n = std::size(s) + 1, k = 0, a, b;
		std::vector<int> x(begin(s), end(s)+1), y(n), ws(std::max(n, lim)), rank(n);
		sa = lcp = y, iota(begin(sa), end(sa), 0);
		for (int j = 0, p = 0; p < n; j = std::max(1, j * 2), lim = p) {
			p = j, iota(begin(y), end(y), n - j);
			for (int i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(begin(ws), end(ws), 0);
			for (int i = 0; i < n; ++i) ws[x[i]]++;
			for (int i = 1; i < lim; ++i) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			for (int i = 1; i < n; ++i) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 1; i < n; ++i) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};
 
int main(){
	std::string s; std::cin >> s;
	SuffixArray SA(s);
	int n = size(s);
	long long k, have = 0; std::cin >> k;
	for (int i = 1; i <= size(s); ++i) {
		if (n - SA.sa[i] - SA.lcp[i] + have < k) have += n - SA.sa[i] - SA.lcp[i];
		else return std::cout << s.substr(SA.sa[i], SA.lcp[i] + k - have) << '\n', 0;
	}
}