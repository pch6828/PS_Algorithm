#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<list>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int pre[10005];
int indegree[10005], n, m, st, en, ans, visit[10005];
vector<pii>adj[10005], rev[10005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		rev[b].push_back({ a, c });
		indegree[b]++;
	}
	
	cin >> st >> en;

	pre[st] = 0;
	queue<int>bfs;
	bfs.push(st);

	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();

		for (pii nxt : adj[now]) {
			indegree[nxt.first]--;
			if (pre[nxt.first] < pre[now] + nxt.second) {
				pre[nxt.first] = pre[now] + nxt.second;
			}

			if (indegree[nxt.first] == 0) {
				bfs.push(nxt.first);
			}
		}
	}

	cout << pre[en] << "\n";

	bfs.push(en);
	visit[en] = 1;
	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();

		for (pii nxt : rev[now]) {
			if (pre[now] == pre[nxt.first] + nxt.second) {
				ans++;
				if (visit[nxt.first] == 0) {
					visit[nxt.first] = 1;
					bfs.push(nxt.first);
				}
			}
		}
	}
	cout << ans;
}