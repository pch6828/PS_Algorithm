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

int pos, b;
string str;
LargeNum a;

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

LargeNum power_LargeNum(const LargeNum &a, int b)
{
    LargeNum result;
    if (b == 0)
    {
        result.push_back(1);
        return result;
    }
    else if (b == 1)
    {
        return a;
    }
    result = power_LargeNum(a, b / 2);
    result = multiply_LargeNum(result, result);
    if (b % 2)
    {
        return multiply_LargeNum(result, a);
    }
    else
    {
        return result;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str >> b;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c == '.')
        {
            pos = str.size() - i - 1;
        }
        else
        {
            a.push_back(c - '0');
        }
    }

    pos *= b;

    LargeNum result = power_LargeNum(a, b);

    string ans;
    for (int i = 0; i < result.size(); i++)
    {
        ans.push_back(result[i] + '0');
        if (i + 1 == pos)
        {
            ans.push_back('.');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
