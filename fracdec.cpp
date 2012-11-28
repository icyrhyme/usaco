/*
ID: icyrhym1
PROG: fracdec
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
//#define DEBUG
#define MAXN 100005
using namespace std;
int main() {

#ifndef DEBUG
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
#endif
	int n, d, sz = 0;
	int rems[MAXN];
	char ans[2 * MAXN];
	bool hasCycle = false;
	int cycleBegin;
	scanf("%d%d", &n, &d);
	memset(rems, -1, sizeof(rems));
	for(int rem = n % d; rem != 0; rem = rem * 10 % d) {
		if(rems[rem] != -1) {
			hasCycle = true;
			cycleBegin = rems[rem];
			break;
		}
		rems[rem] = sz;
		ans[sz++] = '0' + (rem * 10 / d);
	}
	ans[sz] = '\0';
	char out[2 * MAXN];
	if(!hasCycle) {
		if(sz != 0)
			sprintf(out, "%d.%s", n / d, ans);
		else
			sprintf(out, "%d.0", n / d);
	}
	else {
		sprintf(out, "%d.", n /d);
		strncat(out, ans, cycleBegin);
		int len = strlen(out);
		sprintf(out + len, "(%s)", ans + cycleBegin);
	}
	for(int i = 0; out[i]; ++i) {
		putchar(out[i]);
		if(i % 76 == 75)
			putchar('\n');
	}
	putchar('\n');
	return 0;
}
