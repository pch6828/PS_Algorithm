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

ll n, k, mul = 1, ans = 1;
set<ll> remain;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    ll m = n;
    while (m)
    {
        mul *= 10;
        m /= 10;
    }

    mul %= k;
    n %= k;

    m = n;
    remain.insert(m);
    while (m)
    {
        m = (m * mul + n) % k;
        if (remain.count(m))
        {
            ans = -1;
            break;
        }
        remain.insert(m);
        ans++;
    }

    cout << ans;
}
