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

int dp[10001], n, f;
map<int, int> factorial;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i;
    }

    f = 1;
    for (int i = 1; f <= n; i++, f *= i)
    {
        factorial[f] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
            if (i % j == 0)
            {
                dp[i] = min(dp[i], dp[i / j] + dp[j]);
            }
            if (factorial.count(i))
            {
                dp[i] = min(dp[i], dp[factorial[i]]);
            }
        }
    }

    cout << dp[n];
}
