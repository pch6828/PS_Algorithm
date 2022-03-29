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

int pos = 18, n;
string str;
LargeNum a, b;
bool negative = false;

LargeNum multiply_LargeNum(const LargeNum &a, const LargeNum &b)
{
    LargeNum result;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            int idx = i + j;
            while (result.size() <= idx)
            {
                result.push_back(0);
            }
            result[idx] += a[i] * b[j];
            while (result[idx] >= 10)
            {
                int carry = result[idx] / 10;
                result[idx] %= 10;
                idx++;
                if (result.size() == idx)
                {
                    result.push_back(0);
                }
                result[idx] += carry;
            }
        }
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> str;

        for (int i = str.size() - 1; i >= 0; i--)
        {
            char c = str[i];
            if (c != '-' && c != '.')
            {
                a.push_back(c - '0');
            }
            else if (c == '-')
            {
                negative = !negative;
            }
        }
        cin >> str;

        for (int i = str.size() - 1; i >= 0; i--)
        {
            char c = str[i];
            if (c != '-' && c != '.')
            {
                b.push_back(c - '0');
            }
            else if (c == '-')
            {
                negative = !negative;
            }
        }

        string ans;
        LargeNum result = multiply_LargeNum(a, b);
        for (int i = 0; i < result.size(); i++)
        {
            ans.push_back(result[i] + '0');
            if (i + 1 == pos)
            {
                ans.push_back('.');
            }
        }
        if (negative)
        {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";

        a.clear();
        b.clear();
        negative = false;
    }
}
