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
#define MXH 21
#define SIZE 50005

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int root[200001], sz[200001], active[200001], n, m;
vector<int>adj[200001];

int Find(int a) {
	if (a == root[a]) {
		return a;
	}
	return root[a] = Find(root[a]);
}

void Union(int a, int b) {
	int ra = Find(a), rb = Find(b);

	if (ra == rb) {
		return;
	}

	sz[ra] += sz[rb];
	root[rb] = ra;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		root[i] = i;
		sz[i] = 1;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	stack<bool>ans;
	stack<int>query;

	while (n--) {
		int a;
		cin >> a;
		query.push(a);
	}
	int target = 0;
	while (!query.empty()) {
		int a = query.top();
		query.pop();
		target++;
		active[a] = 1;
		for (auto nxt : adj[a]) {
			if (active[nxt]) {
				Union(nxt, a);
			}
		}
		if (sz[Find(a)] == target) {
			ans.push(true);
		}
		else {
			ans.push(false);
		}
	}

	while (!ans.empty()) {
		bool a = ans.top();
		ans.pop();

		if (a) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}


