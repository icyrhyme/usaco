/*
ID: icyrhym1
PROG: inflate
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
//#define DEBUG
#define MAXM 10004
#define INF 100000000
using namespace std;
int main() {
#ifndef DEBUG
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
#endif
	int m, n;
	int pts[MAXM];
	int w, v;
	scanf("%d%d", &m, &n);
	memset(pts, 0, sizeof(pts));
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &v, &w);
		for(int j = 0; j + w <= m; ++j) {
			if(pts[j] + v > pts[j + w])
				pts[j + w] = pts[j] + v;
		}
	}
	int ans = 0;
	for(int j = 0; j <= m; ++j)
		if(pts[j] > ans)
			ans = pts[j];
	printf("%d\n", ans);
	return 0;
}
