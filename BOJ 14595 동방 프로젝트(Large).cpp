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

int n, m, root[1000001];
set<int>room;

int Find(int now) {
	if (root[now] == now) {
		return now;
	}
	return root[now] = Find(root[now]);
}

void Union(int a, int b) {
	int ra = Find(a);
	int rb = Find(b);

	for (int i = ra; Find(i) != rb; i = Find(i+1)) {
		root[i] = rb;
		room.erase(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		root[i] = i;
		room.insert(i);
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	cout << room.size();
}
