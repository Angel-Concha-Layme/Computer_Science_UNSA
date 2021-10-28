#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>

// solution traveler salesman problem
// using dijkstra algorithm

int tsp(int n, int m, int a[][2], int b[][2]) {
	// n: number of cities
	// m: number of roads
	// a: array of roads
	// b: array of cities
	int d[n];
	int p[n];
	int r[n];
	int c[n];
	int u, v;
	int i, j, k;
	int d1, d2, d3;
	int min;
	for (i = 0; i < n; ++i) {
		d[i] = INT_MAX;
		p[i] = -1;
		r[i] = 0;
		c[i] = 0;
	}
	d[0] = 0;
	p[0] = 0;
	r[0] = 1;
	c[0] = 1;
	for (i = 1; i < n; ++i) {
		min = INT_MAX;
		for (j = 0; j < n; ++j) {
			if (r[j] == 0) continue;
			for (k = 0; k < m; ++k) {
				if (a[k][0] == j && r[a[k][1]] == 0) {
					d1 = d[j] + b[a[k][0]][0];
					d2 = d[a[k][1]] + b[a[k][1]][0];
					if (d1 < d2) {
						if (d1 < min) {
							min = d1;
							u = j;
							v = a[k][1];
						}
					} else {
						if (d2 < min) {
                            min = d2;
                            u = a[k][1];
                            v = j;
                        }
                    }
                }
            }
        }
        if (min == INT_MAX) return -1;
        d[v] = min;
        p[v] = u;
        r[v] = 1;
        c[v] = c[u] + 1;
    }
    return d[n - 1];
}

int main(){
    int n, m;
    int a[100][2];
    int b[100][2];
    int i, j;
    while(scanf("%d %d", &n, &m) != EOF){
        for(i = 0; i < m; ++i){
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        for(i = 0; i < n; ++i){
            scanf("%d %d", &b[i][0], &b[i][1]);
        }
        printf("%d\n", tsp(n, m, a, b));
    }
    return 0;
    
}