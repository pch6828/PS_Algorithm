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
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<cassert>

using namespace std;

#define PI 3.14159265359
#define MXH 20
#define SIZE 10005
#define MOD 1000000007

typedef long long ll;
typedef std::pair<int, int> pii;

vector<int>adj[50000];
vector<int>edge[50000];
int root[50000], visit[50000], a, b, n, m;
string result;
bool flag;

int find(int a) {
	if (a == root[a]) {
		return a;
	}
	return root[a] = find(root[a]);
}
void UNION(int a, int b) {
	a = find(a);
	b = find(b);

	root[a] = b;
}

void dfs(int now) {
	visit[now] = 1;

	for (int nxt : adj[now]) {
		if (visit[nxt] == 1) {
			flag = true;
		}
		else if (visit[nxt] == 0) {
			dfs(nxt);
		}
	}
	visit[now] = 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		root[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> result >> b;
		if (result == "=") {
			UNION(a, b);
		}
		else {
			edge[a].push_back(b);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j : edge[i]) {
			int ra = find(i);
			int rb = find(j);
			if (ra == rb) {
				cout << "inconsistent";
				return 0;
			}
			adj[ra].push_back(rb);
		}
	}

	for (int i = 0; i < n; i++) {
		int r = find(i);
		if (flag) {
			cout << "inconsistent";
			return 0;
		}
		if (!visit[r]) {
			dfs(r);
		}
	}
	cout << "consistent";
}
