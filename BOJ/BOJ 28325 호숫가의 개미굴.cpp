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

int n;
vector<ll> rooms;
vector<ll> between_rooms;
ll ans, temp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        rooms.push_back(t);
        ans += t;

        if (t)
            between_rooms.push_back(0);
        else if (!between_rooms.empty())
            between_rooms.back()++;
        else
            temp++;
    }

    if (between_rooms.empty())
    {
        cout << n / 2;
        return 0;
    }

    between_rooms.back() += temp;

    for (ll &t : between_rooms)
    {
        ans += (t + 1) / 2;
    }
    cout << ans;
}