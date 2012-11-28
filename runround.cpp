/*
ID: icyrhym1
PROG: runround
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
//#define DEBUG
#define MAXD 10
#define INF 0x7fffffffffLL
using namespace std;
long long compute(int d[], int sz) {
	long long res = 0;
	for(int i = 0; i < sz; ++i)
		res = res * 10 + d[i];
	return res;
}
long long gen(int d[], int sz, int idx, int di, int cnt, int mask, long long n) {
	if(cnt == sz) {
		long long res = compute(d, sz);
		//printf("%lld\n", res);
		if(res > n)
			return res;
		else
			return INF;
	}
	int nxtIdx = (idx + di) % sz;
	long long ans = INF;
	for(int i = 1; i <= 9; ++i) {
		if(cnt != sz - 1 && !(mask & (1 << i)) && (nxtIdx + i) % sz != nxtIdx && d[(nxtIdx + i) % sz] == 0
				|| cnt == sz - 1 && !(mask & (1 << i)) && (nxtIdx + i) % sz == 0) {
			d[nxtIdx] = i;
			ans = min(ans, gen(d, sz, nxtIdx, i, cnt + 1, mask | (1 << i), n));
			d[nxtIdx] = 0;
		}
	}
	return ans;
}
long long findNext(long long n) {
	int d[MAXD], sz = 0;
	int num = n;
	while(num > 0) {
		d[sz++] = num % 10;
		num /= 10;
	}
	reverse(d, d + sz);
	int firstd = d[0];
	while(true) {
		for(; firstd <= 9; ++firstd) {
			//array, length, idx, digit, cnt, mask
			if(firstd % sz != 0) {
				fill(d, d + sz, 0);
				d[0] = firstd;
				long long ans = gen(d, sz, 0, firstd, 1, 1 << firstd, n);
				d[0] = 0;
				if(ans != INF)
					return ans;
			}
		}
		firstd = 1;
		++sz;
	}
}
int main() {

#ifndef DEBUG
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
#endif
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", findNext(n));
	return 0;
}
