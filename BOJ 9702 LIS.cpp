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

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int tc, n, idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;

	while (tc--) {
		idx++;
		cin >> n;
		vector<int>arr;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			arr.push_back(t);
		}
		int ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			vector<int>lis;
			for (int k = i; k < arr.size(); k++) {
				if (lis.empty() || lis.back() < arr[k]) {
					lis.push_back(arr[k]);
				}
				else {
					*lower_bound(lis.begin(), lis.end(), arr[k]) = arr[k];
				}
				ans += lis.size();
			}
		}
		cout << "Case #" << idx << ": " << ans << "\n";
	}
}
