#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    int checked[26] = {0,}, cnt = 0;
    for(char c : skill){
        checked[c-'A'] = ++cnt;
    }
    for(auto str : skill_trees){
        int prev = 0;
        for(char c : str){
            if(checked[c-'A']){
                if(checked[c-'A']!=prev+1){
                    answer--;
                    break;
                }else{
                    prev = checked[c-'A'];
                }
            }
        }
    }
    return answer;
}