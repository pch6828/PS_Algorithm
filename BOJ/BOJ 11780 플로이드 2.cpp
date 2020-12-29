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

typedef long long ll;
typedef pair<int, int> pii;

int n, m, path[105][105]; 
list<int>previous[105][105];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			path[i][j] = INT_MAX;
		}
		path[i][i] = 0;
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (path[a][b] > c) {
			path[a][b] = c;
			previous[a][b] = list<int>({a, b});
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (path[i][k] != INT_MAX) {
				for (int j = 1; j <= n; j++) {
					if (path[k][j] != INT_MAX) {
						if (path[i][j] > path[k][j] + path[i][k]) {
							path[i][j] = path[i][k] + path[k][j];
							previous[i][j] = previous[i][k];
							previous[i][j].pop_back();
							for (int now : previous[k][j]) {
								previous[i][j].push_back(now);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (path[i][j] == INT_MAX ? 0 : path[i][j]) << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || path[i][j] == INT_MAX) {
				cout << 0;
			}
			else {
				cout << previous[i][j].size() << " ";
				for (int now : previous[i][j]) {
					cout << now << " ";
				}
			}
			cout << "\n";
		}
	}
}