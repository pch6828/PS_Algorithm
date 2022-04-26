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
    int k, s, e, idx;
    bool u;
} Query;

bool cmp(const Query &a, const Query &b)
{
    if (a.k == b.k)
    {
        return a.u;
    }
    return a.k > b.k;
}

int n, m;
vector<Query> queries;
int ans[100001];
int root[100001];
int tree_size[100001];

int FIND(int a)
{
    if (a == root[a])
    {
        return a;
    }
    return root[a] = FIND(root[a]);
}

void UNION(int a, int b)
{
    int ra = FIND(a), rb = FIND(b);
    root[ra] = rb;
    tree_size[rb] += tree_size[ra];
}

int GET_SIZE(int a)
{
    return tree_size[FIND(a)];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        tree_size[i] = 1;
        root[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        queries.push_back({c, a, b, 0, true});
    }
    for (int i = 1; i <= m; i++)
    {
        int k, v;
        cin >> k >> v;
        queries.push_back({k, v, 0, i, false});
    }

    sort(queries.begin(), queries.end(), cmp);

    for (const auto &q : queries)
    {
        if (q.u)
        {
            UNION(q.s, q.e);
        }
        else
        {
            ans[q.idx] = GET_SIZE(q.s) - 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << "\n";
    }
}
