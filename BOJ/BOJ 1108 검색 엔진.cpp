#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<deque>
#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cassert>
#include<fstream>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m, cnt, order[2501], finished[2501], SCC_cnt, SCC_id[2501];
ll score[2501];
vector<int>adj[2501];
stack<int>s;
map<string, int>name;

int dfs(int now) {
	order[now] = ++cnt;
	s.push(now);

	int result = order[now];

	for (int nxt : adj[now]) {
		if (!order[nxt]) {
			result = min(result, dfs(nxt));
		}
		else if (!finished[nxt]) {
			result = min(result, order[nxt]);
		}
	}

	if (result == order[now]) {
		SCC_cnt++;

		while (true) {
			int t = s.top();
			s.pop();
			finished[t] = 1;
			SCC_id[t] = SCC_cnt;
			if (t == now) {
				break;
			}
		}
	}
	return result;
}

ll Get_Score(int now) {
	if (score[now]) {
		return score[now];
	}
	score[now] = 1;
	for (int nxt : adj[now]) {
		if (SCC_id[nxt] != SCC_id[now]) {
			score[now] += Get_Score(nxt);
		}
	}
	return score[now];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a, b;
		int t;
		cin >> a >> t;
		if (!name.count(a)) {
			name[a] = ++m;
		}
		while (t--) {
			cin >> b;
			if (!name.count(b)) {
				name[b] = ++m;
			}
			adj[name[a]].push_back(name[b]);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!order[i]) {
			dfs(i);
		}
	}
	string str;
	cin >> str;
	cout << Get_Score(name[str]);
}


