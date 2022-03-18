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

int virus[201][201], n, k, s, x, y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq[2];

int can_infect(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= n && !virus[x][y];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> virus[i][j];
            if (virus[i][j])
            {
                pq[0].push({virus[i][j], {i, j}});
            }
        }
    }
    cin >> s >> x >> y;

    for (int t = 0; t < s; t++)
    {
        auto &cur_pq = pq[t % 2];
        auto &nxt_pq = pq[(t + 1) % 2];
        while (!cur_pq.empty())
        {
            auto cur = cur_pq.top();
            cur_pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = cur.second.first + dx[i];
                int ty = cur.second.second + dy[i];

                if (can_infect(tx, ty))
                {
                    virus[tx][ty] = cur.first;
                    nxt_pq.push({virus[tx][ty], {tx, ty}});
                }
            }
        }
    }

    cout << virus[x][y];
}
