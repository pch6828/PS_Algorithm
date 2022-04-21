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

int n, house[33][33];
ll dp[33][33][3];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> house[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tx, ty;
            tx = j + 1;
            ty = i;
            if (tx <= n && ty <= n && !house[ty][tx])
            {
                dp[ty][tx][0] += dp[i][j][0] + dp[i][j][1];
            }
            tx = j;
            ty = i + 1;
            if (tx <= n && ty <= n && !house[ty][tx])
            {
                dp[ty][tx][2] += dp[i][j][2] + dp[i][j][1];
            }
            tx = j + 1;
            ty = i + 1;
            if (tx <= n && ty <= n && !house[ty][tx] && !house[ty - 1][tx] && !house[ty][tx - 1])
            {
                dp[ty][tx][1] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}
