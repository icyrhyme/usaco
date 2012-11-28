/*
ID: icyrhym1
PROG: stamps
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 64
#define MAXL 2000005
//#define DEBUG
using namespace std;
int buf[MAXL];
int k, n, st[MAXN];
int main() {
#ifndef DEBUG
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
#endif
	scanf("%d%d", &k, &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &st[i]);
	sort(st, st + n);
	buf[0] = 0;
	for(int i = 1; ;++i) {
		buf[i] = MAXL;
		for(int j = 0; j < n && i - st[j] >= 0; ++j) {
			buf[i] = min(buf[i], buf[i - st[j]] + 1);
		}
		if(buf[i] > k) {
			printf("%d\n", i - 1);
			break;
		}
	}
	return 0;
}
