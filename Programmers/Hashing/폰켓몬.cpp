#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    set<int>s(nums.begin(), nums.end());
    return min(nums.size()/2, s.size());
}