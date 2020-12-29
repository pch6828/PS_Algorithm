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

typedef struct {
	int to;
	ll capacity, flow;
	int reverse;
}Edge;

class EdmondsKarp {
private:
	int source, sink, n;
	vector<vector<Edge>>adj;

public:
	EdmondsKarp(int n, int source, int sink) {
		this->source = source;
		this->n = n;
		this->sink = sink;
		adj.resize(n + 1);
	}

	void add_edge(int from, int to, int capacity) {
		adj[from].push_back({ to, capacity, 0 });
		adj[to].push_back({ from, 0, 0 });

		adj[from].back().reverse = adj[to].size() - 1;
		adj[to].back().reverse = adj[from].size() - 1;
	}

	ll max_flow() {
		ll ans = 0;

		while (true) {
			vector<pii>prev(n + 1, make_pair(-1, -1));
			queue<int>bfs;

			bfs.push(source);
			while (!bfs.empty()) {
				int now = bfs.front();
				bfs.pop();
				bool flag = false;

				for (int i = 0; i < adj[now].size(); i++) {
					Edge& e = adj[now][i];
					if (prev[e.to] == make_pair(-1, -1) && e.capacity - e.flow > 0) {
						bfs.push(e.to);
						prev[e.to] = { now, i };
						if (e.to == sink) {
							flag = true;
							break;
						}
					}
				}
				if (flag) {
					break;
				}
			}

			if (prev[sink] == make_pair(-1, -1)) {
				break;
			}

			ll sum = LLONG_MAX;

			for (int i = sink; i != source; i = prev[i].first) {
				int prev_node = prev[i].first;
				int prev_idx = prev[i].second;
				Edge& e = adj[prev_node][prev_idx];

				sum = min(sum, e.capacity - e.flow);
			}
			for (int i = sink; i != source; i = prev[i].first) {
				int prev_node = prev[i].first;
				int prev_idx = prev[i].second;
				Edge& e = adj[prev_node][prev_idx];

				e.flow += sum;
				adj[e.to][e.reverse].flow -= sum;
			}

			ans += sum;
		}
		return ans;
	}
};

int n, m, arr[101][101], k, st, en;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char road[101][101];

bool is_ok(int i, int j) {
	return i > 0 && i <= n && j > 0 && j <= m && road[i][j] != '#';
}

int valid_in(int n) {
	return n;
}

int valid_out(int n) {
	return n + k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> road[i][j];
			k++;
			arr[i][j] = k;
			if (road[i][j] == 'K') {
				st = k;
			}
			else if (road[i][j] == 'H') {
				en = k;
			}
		}
	}
	EdmondsKarp NetworkFlow(2 * k, valid_out(st), valid_in(en));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (road[i][j] != '#') {
				NetworkFlow.add_edge(valid_in(arr[i][j]), valid_out(arr[i][j]), 1);
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (is_ok(x, y)) {
						NetworkFlow.add_edge(valid_out(arr[i][j]), valid_in(arr[x][y]), 1);
						if (arr[i][j] == st && arr[x][y] == en) {
							cout << -1;
							return 0;
						}
					}
				}
			}
		}
	}

	
	cout << NetworkFlow.max_flow();
}