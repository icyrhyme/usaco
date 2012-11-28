/*
ID: icyrhym1
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>
//#define DEBUG
#define MAXM 10004
#define INF 0x7FFFFFFFLL
#define MAXK 128
using namespace std;
int main() {
#ifndef DEBUG
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
#endif
	int k, n, p[MAXK];
	scanf("%d%d", &k, &n);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &p[i]);
	}
	sort(p, p + k);
	for(int i = 0; i < k; ++i)
		q.push(make_pair(p[i], i));
	for(int i = 0; ; ++i) {
		pair<long long, int> v = q.top();
		if(i == n - 1) {
			printf("%lld\n", v.first);
			break;
		}
		q.pop();
		for(int j = v.second; j < k; ++j) {
			if(v.first * p[j] <= INF)
				q.push(make_pair(v.first * p[j], j));
		}
	}
	return 0;
}
