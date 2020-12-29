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

#define PI 3.14159265359

using namespace std;

pair<int, int> root[100005];
vector<pair<int, pair<int, int>>>edge;
long long ans;
int n;

int find(int a) {
	if (root[a].first == a) {
		return a;
	}
	return root[a].first = find(root[a].first);
}

void UNION(int a, int b, long long w) {
	int ra = find(a), rb = find(b);

	ans += w * root[rb].second * root[ra].second;
	root[rb].first = root[ra].first;
	root[ra].second += root[rb].second;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 1; i < n; i++) {
		int w, a, b;
		cin >> a >> b >> w;
		root[i] = { i, 1 };
		edge.push_back({ w, {a, b} });
	}
	root[n] = { n,1 };
	sort(edge.begin(), edge.end(), greater<pair<int, pair<int, int>>>());

	for (auto ed : edge) {
		UNION(ed.second.first, ed.second.second, ed.first);
	}
	cout << ans;
}
