#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int idx = 1, cnt = 1;
    set<string>dict;
    dict.insert(words[0]);
    for(int i = 1; i < words.size(); i++){
        idx++;
        if(words[i-1].back()!=words[i].front()){
            answer[0] = idx;
            answer[1] = cnt;
            break;
        }else if(dict.count(words[i])){
            answer[0] = idx;
            answer[1] = cnt;
            break;
        }
        
        dict.insert(words[i]);
        if(idx==n){
            idx = 0;
            cnt++;
        }
    }
    
    return answer;
}