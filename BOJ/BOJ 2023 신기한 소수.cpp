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

int len;

bool is_prime(int n)
{
    if (n == 1 || n == 0)
    {
        return false;
    }
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int n, int l)
{
    if (is_prime(n))
    {
        if (l == len)
        {
            cout << n << "\n";
            return;
        }
        for (int i = 1; i <= 9; i++)
        {
            dfs(n * 10 + i, l + 1);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> len;

    for (int i = 0; i < 9; i++)
    {
        dfs(i, 1);
    }
}
