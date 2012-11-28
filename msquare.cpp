/*
ID: icyrhym1
PROG: msquare
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXL 100000
//#define DEBUG
using namespace std;
struct State {
	char board[2][4];
	char move;
	struct State* pre;
	State() {
		pre = NULL;
	}
	bool operator==(const struct State& rhs) const {
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 4; ++j)
				if(board[i][j] != rhs.board[i][j])
					return false;
		return true;
	}
	int hash() {
		int hash = 0;
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 4; ++j)
				hash = hash * 10 + (int)board[i][j];
		return hash;
	}
	struct State* make_move(char c) {
		struct State* ns = new State();
		memcpy(ns->board, board, sizeof(board));
		if(c == 'A') {
			for(int i = 0; i < 4; ++i)
				swap(ns->board[0][i], ns->board[1][i]);
		}
		else if(c == 'B') {
			for(int i = 0; i < 2; ++i) {
				char temp = ns->board[i][3];
				for(int j = 3; j > 0; --j)
					ns->board[i][j] = ns->board[i][j - 1];
				ns->board[i][0] = temp;
			}
		}
		else {
			char temp = ns->board[0][1];
			ns->board[0][1] = ns->board[1][1];
			ns->board[1][1] = ns->board[1][2];
			ns->board[1][2] = ns->board[0][2];
			ns->board[0][2] = temp;
		}
			
		ns->pre = this;
		ns->move = c;
		return ns;
	}
};
int main() {
#ifndef DEBUG
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
#endif
	State* init = new State();
	State* target = new State();
	for(int i = 0, k = 1; i < 2; ++i)
		for(int j = 0; j < 4; ++j, ++k)
			init->board[i][j] = k;
	reverse(init->board[1], init->board[1] + 4);
	for(int j = 0; j < 4; ++j) {
		int num;
		scanf("%d", &num);
		target->board[0][j] = (char)num;
	}
	for(int j = 3; j >= 0; --j) {
		int num;
		scanf("%d", &num);
		target->board[1][j] = (char)num;
	}
	queue<State*> q;
	set<int> vis;
	q.push(init);
	vis.insert(init->hash());
	while(!q.empty()) {
		State* s = q.front();
		/*
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 4; ++j)
				printf("%d ", s->board[i][j]);
			putchar('\n');
		}
		putchar('\n');*/
		q.pop();
		if(*s == *target) {
			delete target;
			target = s;
			break;
		}
		for(int i = 'A'; i <= 'C'; ++i) {
			State* ns = s->make_move(i);
			/*
			putchar(i);
			putchar('\n');
			for(int i = 0; i < 2; ++i) {
				for(int j = 0; j < 4; ++j)
					printf("%d ", ns->board[i][j]);
				putchar('\n');
			}*/
			if(vis.find(ns->hash()) == vis.end()) {
				vis.insert(ns->hash());
				q.push(ns);
			}
			else {
				delete ns;
			}
		}
	}
	State* iter = target;
	vector<char> vc;
	while(iter != NULL) {
		vc.push_back(iter->move);
		iter = iter->pre;
	}
	printf("%d\n", vc.size() - 1);
	for(vector<char>::reverse_iterator it = vc.rbegin() + 1; it != vc.rend(); ++it) {
		putchar(*it);
	}
	putchar('\n');
	return 0;
}
