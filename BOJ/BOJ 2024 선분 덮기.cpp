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

int m, ans;
vector<pii> segments;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;

    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        if (a > b)
        {
            swap(a, b);
        }
        segments.push_back({min(a, m), min(m, b)});
    }
    sort(segments.begin(), segments.end());

    int idx = 0;
    int now_end = 0;
    while (idx < segments.size())
    {
        int max_end = -1;
        for (idx; idx < segments.size(); idx++)
        {
            auto &p = segments[idx];
            if (p.first > now_end)
            {
                break;
            }
            max_end = max(max_end, p.second);
        }
        if (!(~max_end))
        {
            cout << 0;
            return 0;
        }
        else if (max_end > now_end)
        {
            now_end = max_end;
            ans++;
        }
    }
    if (now_end >= m)
    {
        cout << ans;
    }
    else
    {
        cout << 0;
    }
}
