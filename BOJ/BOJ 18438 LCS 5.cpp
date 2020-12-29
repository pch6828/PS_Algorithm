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

char str1[7005], str2[7005], visit[7005];
string trace;

int hirschberg(char* a, char* b, int m, int n) {
	vector<int>arr1[2];
	vector<int>arr2[2];

	if (m == 1 || n == 0) {
		if (!n) {
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			if (a[1] == b[i]) {
				trace.push_back(b[i]);
				return 1;
			}
		}
		return 0;
	}

	int arr1max = m / 2;
	int arr2max = m - arr1max;
	int up = 1;
	int down = 0;

	arr1[0].resize(n + 1);
	arr1[1].resize(n + 1);
	arr2[0].resize(n + 1);
	arr2[1].resize(n + 1);

	for (int i = 0; i <= arr1max; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0 || i == 0) {
				arr1[down][j] = 0;
			}
			else {
				if (a[i] == b[j]) {
					arr1[down][j] = arr1[up][j - 1] + 1;
				}
				else {
					arr1[down][j] = arr1[up][j];
					if (arr1[down][j] < arr1[down][j - 1]) {
						arr1[down][j] = arr1[down][j - 1];
					}
				}
			}
		}
		swap(up, down);
	}
	arr1max = up;

	for (int i = 0; i <= arr2max; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0 || i == 0) {
				arr2[down][j] = 0;
			}
			else {
				if (a[m - i + 1] == b[n - j + 1]) {
					arr2[down][j] = arr2[up][j - 1] + 1;
				}
				else {
					arr2[down][j] = arr2[up][j];
					if (arr2[down][j] < arr2[down][j - 1]) {
						arr2[down][j] = arr2[down][j - 1];
					}
				}
			}
		}
		swap(up, down);
	}

	arr2max = up;

	int ans = 0;
	int idx = 0;

	for (int i = 0; i <= n; i++) {
		if (arr1[arr1max][i] + arr2[arr2max][n - i] > ans) {
			ans = arr1[arr1max][i] + arr2[arr2max][n - i];
			idx = i;
		}
	}

	int x = hirschberg(a, b, m / 2, idx);
	int y = hirschberg(&a[m / 2], &b[idx], m - m / 2, n - idx);
	return x + y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> (str1 + 1) >> (str2 + 1);
	str1[0] = ' ';
	str2[0] = ' ';
	cout << hirschberg(str1, str2, strlen(str1) - 1, strlen(str2)) << "\n";
	cout << trace;
}

