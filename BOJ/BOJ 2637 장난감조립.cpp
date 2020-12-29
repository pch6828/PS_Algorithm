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
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<random>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int indegree[101], outdegree[101], n, m, cnt[101];
vector<pii>adj[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		indegree[b]++;
		outdegree[a]++;
		adj[a].push_back({ b, c });
	}

	queue<int>bfs;
	bfs.push(n);
	cnt[n] = 1;

	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();

		for (auto nxt : adj[now]) {
			indegree[nxt.first]--;
			cnt[nxt.first] += cnt[now] * nxt.second;
			if (!indegree[nxt.first]) {
				bfs.push(nxt.first);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!outdegree[i]) {
			cout << i << " " << cnt[i] << "\n";
		}
	}
}
