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
#include<deque>
#include<list>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int tc, n, m, w;
vector<pair<ll, pii>>edge;

bool bellmanford() {
	vector<ll>dist(n + 1, INT_MAX);

	for (int st = 1; st <= n; st++) {
		if (dist[st] != INT_MAX) {
			continue;
		}
		dist[st] = 0;
		for (int i = 1; i < n; i++) {
			for (auto e : edge) {
				if (dist[e.second.first] != INT_MAX && dist[e.second.second] > dist[e.second.first] + e.first) {
					dist[e.second.second] = dist[e.second.first] + e.first;
				}
			}
		}
		for (auto e : edge) {
			if (dist[e.second.first] != INT_MAX && dist[e.second.second] > dist[e.second.first] + e.first) {
				dist[e.second.second] = dist[e.second.first] + e.first;
				return false;
			}
		}
	}
	return true;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;

	while (tc--) {
		cin >> n >> m >> w;
		edge.clear();
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			edge.push_back({ c, {a, b} });
			edge.push_back({ c, {b, a} });
		}
		while (w--) {
			int a, b, c;
			cin >> a >> b >> c;
			edge.push_back({ -c, {a, b} });
		}
		cout << (bellmanford() ? "NO\n" : "YES\n");
	}
}
