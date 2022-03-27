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

vector<pair<int, string>> team;
string name;
int n, l, o, v, e;

bool cmp(const pair<int, string> &a, const pair<int, string> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> name >> n;
    for (auto c : name)
    {
        if (c == ':')
        {
            l++;
        }
        else if (c == 'O')
        {
            o++;
        }
        else if (c == 'V')
        {
            v++;
        }
        else if (c == 'E')
        {
            e++;
        }
    }

    while (n--)
    {
        int score = 0;
        int tl = l, to = o, tv = v, te = e;
        string t;
        cin >> t;
        for (auto c : t)
        {
            if (c == 'L')
            {
                tl++;
            }
            else if (c == 'O')
            {
                to++;
            }
            else if (c == 'V')
            {
                tv++;
            }
            else if (c == 'E')
            {
                te++;
            }
        }

        score = ((tl + to) * (tl + tv) * (tl + te) * (to + tv) * (to + te) * (tv + te)) % 100;
        team.push_back({score, t});
    }

    sort(team.begin(), team.end(), cmp);
    cout << team.front().second;
}
