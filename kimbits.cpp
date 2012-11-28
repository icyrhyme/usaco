/*
ID: icyrhym1
PROG: kimbits
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
#define MAXN 35
using namespace std;
int N, L;
long long I;
long long C[MAXN][MAXN];
long long gao(int i, int rem, long long idx, long long accu) {
	printf("%d %d %lld %lld\n", i, rem, idx, accu);
	if(i == N)
		return accu;
	else {
		long long sum = 0;
		for(int j = 0; j <= min(rem, N - i - 1); ++j) {
			sum += C[N - i - 1][j];
		}
		printf("%lld %lld\n", sum, idx);
		if(sum < idx)
			return gao(i + 1, rem - 1, idx - sum, (accu << 1) + 1);
		else
			return gao(i + 1, rem, idx, accu << 1);
	}
}
int main() {
#ifndef DEBUG
	FILE *fin = fopen("kimbits.in", "r");
	FILE *fout = fopen("kimbits.out", "w");
#endif
#ifndef DEBUG
	fscanf(fin, "%d%d%lld", &N, &L, &I);
#else
	scanf("%d%d%lld", &N, &L, &I);
#endif
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= i; ++j)
		       if(j == 0 || j == i)
				C[i][j] = 1;
		       else
	       			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];		       
	}
	long long ans = gao(0, L, I, 0);
	for(int i = N - 1; i >= 0; --i)
		if(ans & (1LL << i))
#ifndef DEBUG
			fputc('1', fout);
#else
			putchar('1');
#endif
		else
#ifndef DEBUG
			fputc('0', fout);
#else
			putchar('0');
#endif
#ifndef DEBUG
	fputc('\n', fout);
#else
	putchar('\n');
#endif
	return 0;
}
