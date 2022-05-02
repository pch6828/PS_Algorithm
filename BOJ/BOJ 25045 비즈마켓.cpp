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

int n, m;
vector<ll> sat, cost;
ll ans, t;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sat.push_back(t);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        cost.push_back(t);
    }

    sort(sat.begin(), sat.end(), greater<ll>());
    sort(cost.begin(), cost.end());

    for (int i = 0; i < min(n, m); i++)
    {
        if (cost[i] > sat[i])
        {
            break;
        }
        ans += sat[i] - cost[i];
    }
    cout << ans;
}
