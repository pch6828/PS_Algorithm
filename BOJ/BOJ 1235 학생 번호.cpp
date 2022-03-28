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

class Trie
{
    class Node
    {

    public:
        Node()
        {
            for (int i = 0; i < 10; i++)
            {
                child[i] = NULL;
            }
            num_child = 0;
        }
        void insert(const string &str, int idx)
        {
            num_child++;
            if (idx < 0)
            {
                return;
            }
            int digit = str[idx] - '0';
            if (!child[digit])
            {
                child[digit] = new Node();
            }
            child[digit]->insert(str, idx - 1);
        }
        int traverse_max()
        {
            int max_depth = 0;
            if (num_child == 1)
            {
                return 0;
            }
            for (int i = 0; i < 10; i++)
            {
                if (child[i])
                {
                    max_depth = max(max_depth, child[i]->traverse_max());
                }
            }
            return max_depth + 1;
        }

        Node *child[10];
        int num_child;
    };

public:
    Node root;
    void insert(const string &str)
    {
        root.insert(str, str.size() - 1);
    }
    int traverse_max()
    {
        return root.traverse_max();
    }
};

int n;
string id;
Trie trie;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> id;
        trie.insert(id);
    }
    cout << trie.traverse_max();
}
