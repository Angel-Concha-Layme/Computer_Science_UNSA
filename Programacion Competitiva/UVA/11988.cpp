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
	char line[100001];
	while (scanf("%s", line) != EOF) {
		std::list<char> l;
		int len = strlen(line);
		std::list<char>::iterator it = l.begin();
		for (int i = 0; i < len; i++) {
			if (line[i] == '[') {
				it = l.begin();
			} else if (line[i] == ']') {
				it = l.end();
			} else {
				l.insert(it, line[i]);
			}
		}
		for (it = l.begin(); it != l.end(); it++) {
			printf("%c", *it);
		}
		printf("\n");
	}
	return 0;
}