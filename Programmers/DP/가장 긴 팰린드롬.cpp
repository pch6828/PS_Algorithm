#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int palindrome_range[20001], n, m;
vector<int>str;

template<class T>
void manacher(vector<T> str, int len) {
    int radius = 0, point = 0;

    for (int i = 0; i < len; i++) {
        if (i <= radius) {
            palindrome_range[i] = min(palindrome_range[2 * point - i], radius - i);
        }
        else {
            palindrome_range[i] = 0;
        }
        while (i - palindrome_range[i] - 1 >= 0 && i + palindrome_range[i] + 1 < len && str[i - palindrome_range[i] - 1] == str[i + palindrome_range[i] + 1]) {
            palindrome_range[i]++;
        }

        if (radius < i + palindrome_range[i]) {
            radius = i + palindrome_range[i];
            point = i;
        }
    }
}

int solution(string s)
{
    int answer=0;
    for (auto c : s) {
        str.push_back(c);
        str.push_back(' ');
    }

    manacher(str, str.size());

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        int len = palindrome_range[i] * 2 + 1;

        if (str[i] == ' ') {
            if (palindrome_range[i] % 2) {
                len /= 2;
            }
            else {
                len -= 2;
                len /= 2;
            }
            len++;
        }
        else {
            if (palindrome_range[i] % 2) {
                len -= 2;
                len /= 2;
            }
            else {
                len /= 2;
            }
            len++;
        }
        ans = max(ans, len);
    }
    return ans;
}