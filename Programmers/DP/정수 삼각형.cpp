#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 1; i < triangle.size(); i++){
        triangle[i].front() += triangle[i-1].front();
        triangle[i].back() += triangle[i-1].back();
        for(int j = 1; j < i; j++){
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    for(int i : triangle.back()){
        answer = max(answer, i);
    }
    return answer;
}