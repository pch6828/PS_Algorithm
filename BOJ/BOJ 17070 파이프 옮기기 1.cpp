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

typedef struct
{
    int x, y, dir;
} Pipe;

int n, ans, house[17][17];

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

    queue<Pipe> bfs;
    bfs.push({2, 1, 0});

    while (!bfs.empty())
    {
        int tx, ty;
        Pipe pipe = bfs.front();
        bfs.pop();
        if (pipe.x == n && pipe.y == n)
        {
            ans++;
        }

        if (pipe.dir != 2)
        {
            tx = pipe.x + 1;
            ty = pipe.y;
            if (tx <= n && ty <= n && !house[ty][tx])
            {
                bfs.push({tx, ty, 0});
            }
        }
        if (pipe.dir != 0)
        {
            tx = pipe.x;
            ty = pipe.y + 1;
            if (tx <= n && ty <= n && !house[ty][tx])
            {
                bfs.push({tx, ty, 2});
            }
        }

        tx = pipe.x + 1;
        ty = pipe.y + 1;
        if (tx <= n && ty <= n && !house[ty][tx] && !house[ty][tx - 1] && !house[ty - 1][tx])
        {
            bfs.push({tx, ty, 1});
        }
    }

    cout << ans;
}
