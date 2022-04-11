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

ll n, maximum = LLONG_MIN, minimum = LLONG_MAX, average;
int cnt[8001], max_cnt;
vector<ll> arr;
vector<ll> modes;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        arr.push_back(t);
        maximum = max(maximum, t);
        minimum = min(minimum, t);
        cnt[t + 4000]++;
        max_cnt = max(cnt[t + 4000], max_cnt);
        average += t;
    }

    sort(arr.begin(), arr.end());
    for (ll i = -4000; i <= 4000; i++)
    {
        if (cnt[i + 4000] == max_cnt)
        {
            modes.push_back(i);
        }
    }
    average *= 10;
    cout << ((average / n) / 10 + (abs(average / n) % 10 >= 5) * (average >= 0 ? 1 : -1)) << "\n"
         << arr[n / 2] << "\n"
         << (modes.size() == 1 ? modes[0] : modes[1]) << "\n"
         << maximum - minimum;
}
