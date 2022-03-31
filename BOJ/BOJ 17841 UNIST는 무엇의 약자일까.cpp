#include <cstdio>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <list>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> LargeNum;

int n, dp[100001][6];
string target = "UNIST", str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        dp[i][0] = 1;

        for (int j = 0; j < 5; j++)
        {
            dp[i][j + 1] = dp[i - 1][j + 1];
        }
        for (int j = 0; j < 5; j++)
        {
            for (int idx1 = 0, idx2 = j; idx1 < min(5, (int)(str.size())) && idx2 < 5; idx1++, idx2++)
            {
                if (str[idx1] == target[idx2])
                {
                    dp[i][idx2 + 1] += dp[i - 1][j];
                    dp[i][idx2 + 1] %= MOD;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << dp[n][5];
}
