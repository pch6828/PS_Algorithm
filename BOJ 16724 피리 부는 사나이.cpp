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
#define PI 3.14159265359
#define MXH 20
#define SIZE 40005

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int parent[1000001], n, m;
set<int>component;

int Find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int ra = Find(a), rb = Find(b);

	if (ra != rb) {
		parent[ra] = rb;
		component.erase(ra);
	}
}

bool is_ok(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		parent[i] = i;
		component.insert(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			int a = i, b = j;
			int now = (a - 1) * m + b;
			
			if (c == 'D') {
				a++;
			}
			else if (c == 'U') {
				a--;
			}
			else if (c == 'L') {
				b--;
			}
			else if (c == 'R') {
				b++;
			}
			if (is_ok(a, b)) {
				int nxt = (a - 1) * m + b;
				Union(now, nxt);
			}
		}
	}
	cout << component.size();
}


