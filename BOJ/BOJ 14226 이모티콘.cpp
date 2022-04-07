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

int n;
bool visit[2001][2001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    queue<pair<pii, int>> bfs;

    bfs.push({{1, 0}, 0});
    visit[1][0] = true;

    while (!bfs.empty())
    {
        auto now = bfs.front();
        bfs.pop();

        int screen = now.first.first;
        int clipboard = now.first.second;
        int t = now.second;

        if (screen == n)
        {
            cout << t;
            return 0;
        }

        if (screen - 1 > 0 && !visit[screen - 1][clipboard])
        {
            visit[screen - 1][clipboard] = true;
            bfs.push({{screen - 1, clipboard}, t + 1});
        }
        if (screen + clipboard < 2 * n && !visit[screen + clipboard][clipboard])
        {
            visit[screen + clipboard][clipboard] = true;
            bfs.push({{screen + clipboard, clipboard}, t + 1});
        }
        if (!visit[screen][screen])
        {
            visit[screen][screen] = true;
            bfs.push({{screen, screen}, t + 1});
        }
    }
}
