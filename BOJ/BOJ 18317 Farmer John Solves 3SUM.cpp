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
typedef pair<ll, ll> pll;

ll exist[2000001], arr[5001], dp[5001][5001];
int n, q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = i - 1; j > 0; j--) {
			ll sum = arr[i] + arr[j];
			if (abs(sum) > 1000000) {
				exist[arr[j] + 1000000]++;
				continue;
			}
			dp[j][i] += exist[-sum + 1000000];
			exist[arr[j] + 1000000]++;
		}
		for (int j = i - 1; j > 0; j--) {
			exist[arr[j] + 1000000]--;
		}
	}

	for (int j = 1; j < n; j++) {
		for (int i = 1; i <= n - j; i++) {
			dp[i][i + j] += dp[i][i + j - 1] + dp[i + 1][i + j];
			dp[i][i + j] -= dp[i + 1][i + j - 1];
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}
