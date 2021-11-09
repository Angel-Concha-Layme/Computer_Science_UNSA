#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>

#define MAXN 81
char s[MAXN];

int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%s", s);
        int ret = 0, O = 0;
        for (int i = 0; s[i]; i++) {
            O = s[i] == 'O' ? O + 1 : 0;
            ret += O;
        }
        printf("%d\n", ret);
    }
    return 0;
}