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
	std::string s; // the input string
	int n; // the length of the input string
	std::vector<std::vector<int>> P; // the suffix array

	SuffixArray(std::string &_s) : s(_s), n(_s.length()) {
        construct();
    }

	void construct() {
		P.push_back(std::vector<int>(n, 0));
		compress();
		std::vector<int> occ(n + 1, 0), s1(n, 0), s2(n, 0);
		for ( int k = 1, cnt = 1; cnt / 2 < n; ++k, cnt *= 2 ) {
			P.push_back(std::vector<int> (n, 0));
			fill(occ.begin(), occ.end(), 0);
			for ( int i = 0; i < n; ++i )
				occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]++; // count occurrences of each character

			partial_sum(occ.begin(), occ.end(), occ.begin());

			for ( int i = n - 1; i >= 0; --i )
				s1[--occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]] = i; // compute inverse permutation

			fill(occ.begin(), occ.end(), 0);

			for ( int i = 0; i < n; ++i )
				occ[P[k-1][s1[i]]]++; // count occurrences of each character

			partial_sum(occ.begin(), occ.end(), occ.begin());

			for ( int i = n - 1; i >= 0; --i )
				s2[--occ[P[k-1][s1[i]]]] = s1[i]; // compute inverse permutation

			for ( int i = 1; i < n; ++i ) {
				P[k][s2[i]] = same(s2[i], s2[i - 1], k, cnt)
					? P[k][s2[i - 1]] : i; // compute partial order
			}
		}
	}

	bool same(int i, int j, int k, int l) {
		return P[k - 1][i] == P[k - 1][j] && (i + l < n ? P[k - 1][i + l] : -1)	== (j + l < n ? P[k - 1][j + l] : -1); // check if two suffixes are the same
	}

	void compress() {
		std::vector<int> cnt(256, 0);
		for ( int i = 0; i < n; ++i )
            cnt[s[i]]++; // count occurrences of each character
		for ( int i = 0, mp = 0; i < 256; ++i )
			  if (cnt[i] > 0) cnt[i] = mp++; // map each character to a unique integer
		for ( int i = 0; i < n; ++i )
        P[0][i] = cnt[s[i]]; // map each character to its unique integer
	}

	std::vector <int> &get_array() {
      return P.back();
    }

	int lcp(int x, int y) {
		int ret = 0;
		if (x == y)
        return n - x;
		for ( int k = P.size() - 1; k >= 0 && x < n && y < n; --k ) // iterate over layers
        if (P[k][x] == P[k][y]) {
            x += 1 << k; // move x and y to the next level
            y += 1 << k; // move x and y to the next level
            ret += 1 << k; // add the length of the common prefix
			}
		return ret;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while (T--) {
		std::string s;
		std::cin >> s;
		int n = s.length();
		SuffixArray sa(s);

		std::vector<int> &arr = sa.get_array();

		std::vector<int> inv(n, -1);
		for ( int i = 0; i < n; ++i ) {
			inv[arr[i]] = i; // inverse permutation
		}

		std::vector<int> lcp(n, 0);
		for ( int i = 1; i < n; ++i ) {
			lcp[i] = sa.lcp(inv[i - 1], inv[i]); // compute lcp
		}

		long long ans = 0;
		for ( int i = 1; i < n; ++i ) {
        if ( lcp[i] > lcp[i - 1] )
          ans += lcp[i] - lcp[i - 1]; // add the length of the common prefix
		}

		std::cout << ans << std::endl;
	}
	return 0;
}