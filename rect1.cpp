/*
ID: icyrhym1
PROG: rect1
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
//from zoj 1128
struct rect
{
	int x1, y1, x2, y2, c;
};
struct rects
{
	int sz;
	rect ra[MAXN];
	void init()
	{
		sz = 0;
	}
	void del(int idx)
	{
		ra[idx] = ra[--sz];
	}
	void add(int x1, int y1, int x2, int y2, int c)
	{
		ra[sz].x1 = x1;
		ra[sz].y1 = y1;
		ra[sz].x2 = x2;
		ra[sz].y2 = y2;
		ra[sz].c = c;
		++sz;
	}
	void cut(int idx, int x1, int y1, int x2, int y2)
	{
		rect r = ra[idx];
		if(x1 >= r.x2 || x2 <= r.x1 || y1 >= r.y2 || y2 <= r.y1)
			return;
		int k1 = max(x1, r.x1), k2 = min(x2, r.x2);
		if(k1 > r.x1)
			add(r.x1, r.y1, k1, r.y2, r.c);
		if(k2 < r.x2)
			add(k2, r.y1, r.x2, r.y2, r.c);
		int k3 = max(y1, r.y1), k4 = min(y2, r.y2);
		if(k3 > r.y1)
			add(k1, r.y1, k2, k3, r.c);
		if(k4 < r.y2)
			add(k1, k4, k2, r.y2, r.c);
		del(idx);
	}
	void add_ol(int x1, int y1, int x2, int y2, int c)
	{
		for(int i = sz - 1; i >= 0; --i)
			cut(i, x1, y1, x2, y2);
		add(x1, y1, x2, y2, c);
	}
};

int main() {
#ifndef DEBUG
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
#endif
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	rects rs;
	rs.add_ol(0, 0, a, b, 1);
	for(int i = 0; i < n; ++i) {
		int x1, y1, x2, y2, c;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		rs.add_ol(x1, y1, x2, y2, c);
	}
	map<int, int> mp;
	for(int i = 0; i < rs.sz; ++i) {
		rect r = rs.ra[i];
		mp[r.c] += (r.x2 - r.x1) * (r.y2 - r.y1);
	}
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}
