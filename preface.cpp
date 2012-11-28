/*
ID: icyrhym1
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 16
using namespace std;
void calc(int num, int d, int f, int cnt[]) {
	if(num <= 3) {
		cnt[d] += f * num;
	}
	else if(num <= 8) {
		cnt[d + 1] += f;
		cnt[d] += f * abs(5 - num);
	}
	else {
		cnt[d + 2] += f;
		cnt[d] += f * abs(10 - num);
	}
}	
int main() {

#ifndef DEBUG
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
#endif
	int n;
	int cnt[MAXN];
	char sym[MAXN] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	fill(cnt, cnt + MAXN, 0);
	scanf("%d", &n);
	int num = n, p = 1, d = 0, f;
	while(num != 0) {
		for(int i = 1; i <= 9; ++i) {
			f = n / (p * 10) * p;
			if(num % 10 == i)
				f += n % p + 1;
			else if(num % 10 > i)
				f += p;
			calc(i, d, f, cnt);
		}
		num /= 10;
		p *= 10;
		d += 2;
	}
	for(int i = 0; i < MAXN; ++i) {
		if(cnt[i] > 0) {
			printf("%c %d\n", sym[i], cnt[i]);
		}
	}
	return 0;
}
