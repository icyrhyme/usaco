/*
ID: icyrhym1
PROG: subset
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
//#define DEBUG
#define MAXN 1024
using namespace std;
int main() {

#ifndef DEBUG
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
#endif
	int n;
	long long sum[MAXN];
	scanf("%d", &n);
	if((n + 1) * n / 2 % 2 == 1) {
		printf("0\n");
		return 0;
	}
	fill(sum, sum + MAXN, 0LL);
	sum[0] = 1;
	int half = (n + 1) * n / 2 / 2;
	for(int i = 1; i <= n; ++i) {
		for(int j = min((i + 1) * i / 2 - i, half); j >= 0; --j) {
			sum[j + i] += sum[j];
		}
	}
	printf("%lld\n", sum[half] / 2);
	return 0;
}
