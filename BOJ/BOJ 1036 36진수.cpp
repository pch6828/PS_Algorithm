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
int n, k;
LargeNum cnt[36];
vector<int> digit_order;
set<int> will_be_z;
LargeNum ans;

bool cmp_large_num(const LargeNum &a, const LargeNum &b)
{
    if (a.size() == b.size())
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            return a[i] > b[i];
        }
        return true;
    }
    return a.size() > b.size();
}

bool cmp_benefit(const int &digit1, const LargeNum &a, const int &digit2, const LargeNum &b)
{
    LargeNum benefit1;
    LargeNum benefit2;
    int idx;
    for (int i = 0; i < a.size(); i++)
    {
        idx = i;
        if (benefit1.size() <= idx)
        {
            benefit1.push_back(0);
        }
        benefit1[idx] += (35 - digit1) * a[i];
        while (benefit1[idx] >= 36)
        {
            int carry = benefit1[idx] / 36;
            benefit1[idx] %= 36;
            idx++;
            if (idx == benefit1.size())
            {
                benefit1.push_back(0);
            }
            benefit1[idx] += carry;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        idx = i;
        if (benefit2.size() <= idx)
        {
            benefit2.push_back(0);
        }
        benefit2[idx] += (35 - digit2) * b[i];
        while (benefit2[idx] >= 36)
        {
            int carry = benefit2[idx] / 36;
            benefit2[idx] %= 36;
            idx++;
            if (idx == benefit2.size())
            {
                benefit2.push_back(0);
            }
            benefit2[idx] += carry;
        }
    }
    return cmp_large_num(benefit1, benefit2);
}

bool cmp(int a, int b)
{
    return cmp_benefit(a, cnt[a], b, cnt[b]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 36; i++)
    {
        cnt[i].push_back(0);
        digit_order.push_back(i);
    }

    cin >> n;

    while (n--)
    {
        string str;
        cin >> str;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            char c = str[i];
            int digit;
            if ('A' <= c && c <= 'Z')
            {
                digit = 10 + c - 'A';
            }
            else
            {
                digit = c - '0';
            }
            while (cnt[digit].size() < str.size() - i)
            {
                cnt[digit].push_back(0);
            }
            int idx = str.size() - i - 1;
            cnt[digit][idx]++;
            while (cnt[digit][idx] == 36)
            {
                cnt[digit][idx] = 0;
                idx++;
                if (idx == cnt[digit].size())
                {
                    cnt[digit].push_back(0);
                }
                cnt[digit][idx]++;
            }
        }
    }
    cin >> k;
    stable_sort(digit_order.begin(), digit_order.end(), cmp);

    for (int digit : digit_order)
    {
        if (k && digit != 35)
        {
            will_be_z.insert(digit);
            k--;
        }
    }

    for (int i = 0; i < 36; i++)
    {
        int digit = i;
        if (will_be_z.count(digit))
        {
            digit = 35;
        }
        for (int j = 0; j < cnt[i].size(); j++)
        {
            while (ans.size() <= j)
            {
                ans.push_back(0);
            }

            ans[j] += digit * cnt[i][j];

            int idx = j;
            while (ans[idx] >= 36)
            {
                int carry = ans[idx] / 36;
                ans[idx] %= 36;
                idx++;
                if (idx == ans.size())
                {
                    ans.push_back(0);
                }
                ans[idx] += carry;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (int d : ans)
    {
        if (d >= 10)
        {
            cout << char(d - 10 + 'A');
        }
        else
        {
            cout << d;
        }
    }
}
