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
	char s[20];
	int qnum, p, n;
	std::priority_queue<std::pair<int, std::pair<int, int> >,
			std::vector<std::pair<int, std::pair<int, int> > >,
			std::greater<std::pair<int, std::pair<int, int> > > > pq;

	while (scanf("%s", s), strcmp("#", s)) {
		scanf("%d %d", &qnum, &p);
		pq.push(std::pair<int, std::pair<int, int> >(p, std::pair<int, int>(qnum, p)));
	}

	scanf("%d", &n);
	while (n--) {
		std::pair<int, std::pair<int, int> > pr = pq.top();
		pq.pop();

		printf("%d\n", pr.second.first);

		pr.first += pr.second.second;
		pq.push(pr);
	}
	return 0;
}