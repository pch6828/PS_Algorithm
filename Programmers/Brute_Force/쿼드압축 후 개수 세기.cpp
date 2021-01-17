#include <string>
#include <vector>

using namespace std;

string backtrack(vector<vector<int>>& arr, int x, int y, int n) {
    string res;
    if (n == 0) {
        res.push_back(arr[x][y]+'0');
        return res;
    }

    string a = backtrack(arr, x, y, n / 2);
    string b = backtrack(arr, x, y + n / 2, n / 2);
    string c = backtrack(arr, x + n / 2, y, n / 2);
    string d = backtrack(arr, x + n / 2, y + n / 2, n / 2);

    if (a.size() == 1 && b.size() == 1 && c.size() == 1 && d.size() == 1 && a == b && b == c && c == d) {
        return a;
    }
    res = "(" + a + b + c + d + ")";
    return res;
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    string quadtree = backtrack(arr, 0, 0, arr.size());
    int zero = 0, one = 0;
    for(auto c:quadtree){
        if(c=='0'){
            zero++;
        }else if(c=='1'){
            one++;
        }
    }
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}