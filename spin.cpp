/*
ID: icyrhym1
PROG: spin
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 64
#define MAXL 2000005
//#define DEBUG
using namespace std;
struct Wheel {
	int v, wsz, base[5], ext[5];
};
bool in_range(struct Wheel& w, int t, int r) {
	for(int i = 0; i < w.wsz; ++i) {
		int begin = (w.base[i] + w.v * t) % 360;
		int end = (w.base[i] + w.ext[i] + w.v * t) % 360;
		if(begin <= end && r >= begin && r <= end ||
				begin > end && (r >= begin || r <= end)) {
			return true;
		}
	}
	return false;
}
int main() {
#ifndef DEBUG
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
#endif
	struct Wheel a[5];
	for(int i = 0; i < 5; ++i) {
		scanf("%d%d", &a[i].v, &a[i].wsz);
		for(int j = 0; j < a[i].wsz; ++j) {
			scanf("%d%d", &a[i].base[j], &a[i].ext[j]);
		}
	}
	for(int i = 0; i < 360; ++i) {
		for(int j = 0; j < 360; ++j) {
			bool flag = true;
			for(int k = 0; k < 5; ++k) {
				if(!in_range(a[k], i, j)) {
					flag = false;
					break;
				}
			}
			if(flag) {
				printf("%d\n", i);
				goto label;
			}
		}
	}
	printf("none\n");
label:
	return 0;
}
