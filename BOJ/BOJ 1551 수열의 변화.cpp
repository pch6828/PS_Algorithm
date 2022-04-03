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

int n, k, arr[20];

int main(void)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d,", &arr[i]);
    }

    while (k--)
    {
        n--;
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i + 1] - arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << (i == n - 1 ? "" : ",");
    }
}
