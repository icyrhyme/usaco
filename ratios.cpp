/*
ID: icyrhym1
PROG: ratios
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 64
#define MAXL 2000005
//#define DEBUG
using namespace std;
int main() {
#ifndef DEBUG
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
#endif
	int r[4][3];
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 3; ++j)
			scanf("%d", &r[i][j]);
	int res[3], ans;
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			for(int k = 0; k < 100; ++k) {
				if(i == j && j == k && i == 0)
					continue;
				ans = -1;
				bool flag = true;
				for(int l = 0; l < 3; ++l) {
					res[l] = i * r[1][l] + j * r[2][l] + k * r[3][l];
					if(r[0][l] != 0 && (res[l] % r[0][l] != 0 || ans != -1 && res[l] / r[0][l] != ans) || r[0][l] == 0 && res[l] != 0) {
						flag = false;
						break;
					}
					if(r[0][l] != 0)
						ans = res[l] / r[0][l];
				}
				if(flag) {
					printf("%d %d %d %d\n", i, j, k, ans);
					goto retLabel;
				}
			}
	printf("NONE\n");
retLabel:
	return 0;
}
