/*
ID: icyrhym1
PROG: fact4
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
//#define DEBUG
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define MAXN 50000
using namespace std;

int main() {
#ifndef DEBUG
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
#endif
	int n, fives;
	scanf("%d", &n);
	fives = 0;
	int p = 5;
	while(n >= p) {
		fives += n / p;
		p *= 5;
	}
	int res = 1;
	for(int i = 1; i <= n; ++i) {
		int num = i;
		while(num % 5 == 0)
			num /= 5;
		while(num % 2 == 0 && fives > 0) {
			num /= 2;
			--fives;
		}
		res = res * num % 10;
	}
	printf("%d\n", res);
	return 0;
}
