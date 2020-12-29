#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int>dict;
    
    for(auto v : clothes){
        dict[v[1]]++;
    }
    for(auto p : dict){
        answer*=(p.second+1);
    }
    return answer-1;
}