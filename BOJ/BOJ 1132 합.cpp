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
ll sum[10], answer;
string str, idx = "ABCDEFGHIJ";
bool cannot_be_zero[10];

bool cmp(const char &c1, const char &c2)
{
    return sum[c1 - 'A'] < sum[c2 - 'A'];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n--)
    {
        cin >> str;

        cannot_be_zero[str[0] - 'A'] = true;
        ll k = 1;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            sum[str[i] - 'A'] += k;
            k *= 10;
        }
    }
    sort(idx.begin(), idx.end(), cmp);

    if (cannot_be_zero[idx[0] - 'A'])
    {
        for (int i = 0; i < 10; i++)
        {
            if (!cannot_be_zero[idx[i] - 'A'])
            {
                swap(idx[0], idx[i]);
                break;
            }
        }
    }
    sort(idx.begin() + 1, idx.end(), cmp);
    for (int i = 0; i < 10; i++)
    {
        answer += i * sum[idx[i] - 'A'];
    }
    cout << answer;
}
