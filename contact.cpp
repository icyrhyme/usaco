/*
ID: icyrhym1
PROG: contact
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#define MAXL 200005
//#define DEBUG
using namespace std;
bool cmp(pair<pair<int, int>, int> t, pair<pair<int, int>, int> o) {
	if(t.second != o.second)
		return t.second > o.second;
	else if(t.first.first != o.first.first)
		return t.first.first < o.first.first;
	else
		return t.first.second < o.first.second;
}
void print(pair<int, int> p) {
	vector<int> tmp;
	for(int i = 0; i < p.first; ++i) {
		tmp.push_back(p.second & 1);
		p.second >>= 1;
	}
	for(vector<int>::reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it)
		printf("%d", *it);
}
int main() {
#ifndef DEBUG
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
#endif
	int a, b, n;
	char seq[MAXL];
	scanf("%d%d%d", &a, &b, &n);
	for(int i = 0;;) {
		char c = getchar();
		if(c == EOF) {
			seq[i] = '\0';
			break;
		}
		else if(c != '\n')
			seq[i++] = c;
	}
	map<pair<int, int>, int> mp;
	int length = strlen(seq);
	for(int i = a; i <= b; ++i) {
		//printf("i = %d\n", i);
		if(i > length)
			break;
		int num = 0;
		for(int j = 0; j < i; ++j)
			num = (num << 1) + (seq[j] == '1' ? 1 : 0);
		mp[make_pair(i, num)] += 1;
		//printf("num:%d\n", num);
		for(int j = i; j < length; ++j) {
			num = num & (~(1 << (i - 1)));
			num = (num << 1) + (seq[j] == '1' ? 1 : 0);
			mp[make_pair(i, num)] += 1;
			//printf("num:%d\n", num);
		}
	}
	vector<pair<pair<int, int>, int> > v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);
	for(int i = 0, cnt = 0; i < v.size() && cnt < n;) {
		printf("%d\n", v[i].second);
		++cnt;
		int j;
		vector<pair<int, int> > tmp;
		for(j = i; j < v.size() && v[j].second == v[i].second; ++j) {
			tmp.push_back(v[j].first);
		}	
		for(int k = 0; k < tmp.size(); ++k) {
			print(tmp[k]);
			if(k % 6 == 5 || k == tmp.size() - 1)
				putchar('\n');
			else
				putchar(' ');
		}
		i = j;
	}
	return 0;
}
