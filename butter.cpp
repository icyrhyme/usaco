/*
ID: icyrhym1
PROG: butter
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
#define MAXN 900
//#define DEBUG
using namespace std;
int main() {
#ifndef DEBUG
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
#endif
	int n, p, c, cow[MAXN];
	vector<pair<int, int> > g[MAXN];
	scanf("%d%d%d", &n, &p, &c);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &cow[i]);
		--cow[i];
	}
	for(int i = 0; i < c; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	int d[MAXN], opt = -1;
	for(int i = 0; i < p; ++i) {
		memset(d, -1, sizeof(d));
		queue<int> q;
		set<int> inq;
		d[i] = 0;
		q.push(i);
		inq.insert(i);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			inq.erase(u);
			vector<pair<int, int> >::iterator it;
			for(it = g[u].begin(); it != g[u].end(); ++it) {
				int v = it->first;
				int w = it->second;
				if(d[v] == -1 || d[u] + w < d[v]) {
					d[v] = d[u] + w;
					q.push(v);
					inq.insert(v);
				}
			}
		}
		int dsum = 0;
		for(int i = 0; i < n; ++i) {
			dsum += d[cow[i]];
		}
		if(opt == -1 || dsum < opt)
			opt = dsum;
	}
	printf("%d\n", opt);
	return 0;
}
