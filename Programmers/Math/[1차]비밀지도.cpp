#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        arr1[i] |= arr2[i];
        string str;
        for(int j = 0; j < n; j++){
            str.push_back((arr1[i]%2)?'#':' ');
            arr1[i]/=2;
        }
        reverse(str.begin(), str.end());
        answer.push_back(str);
    }
    return answer;
}