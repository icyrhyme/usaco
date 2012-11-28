/*
ID: icyrhym1
PROG: inflate.cpp
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
//#define DEBUG
#define MAXN 128
#define INF 100000000
using namespace std;
int main() {
#ifndef DEBUG
	freopen("inflate.cpp.in", "r", stdin);
	freopen("inflate.cpp.out", "w", stdout);
#endif
	int n, g[MAXN][MAXN];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &g[i][j]);
	int cost = 0, sz = 1;
	int d[MAXN];
	bool inTree[MAXN];
	for(int i = 0; i < n; ++i) {
		d[i] = INF;
		inTree[i] = false;
	}
	inTree[0] = true;
	for(int i = 0; i < n; ++i) {
		if(!inTree[i] && g[0][i] < d[i])
			d[i] = g[0][i];
	}
	while(sz < n) {
		int idx = -1;
		for(int i = 0; i < n; ++i)
			if(!inTree[i] && (idx == -1 || d[i] < d[idx]))
				idx = i;
		inTree[idx] = true;
		cost += d[idx];
		for(int i = 0; i < n; ++i)
			if(!inTree[i] && g[idx][i] < d[i])
				d[i] = g[idx][i];
		++sz;
	}
	printf("%d\n", cost);
	return 0;
}
