#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>&b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>arr;
    s.pop_back();
    istringstream sin(s);
    char c;
    sin>>c;
    vector<int>temp;
    int t = 0;
    while(true){
        sin>>c;
        if(c>='0'&&c<='9'){
            t*=10;
            t+=c-'0';
        }else if(c=='}'||c==','){
            temp.push_back(t);
            t = 0;
        }
        if(c=='}'){
            arr.push_back(temp);
            temp.clear();
            if(sin>>c){
                sin>>c;
            }else{
                break;
            }
        }
    }
    sort(arr.begin(), arr.end(), compare);
    set<int>has;
    for(auto& v:arr){
        for(int i:v){
            if(!has.count(i)){
                answer.push_back(i);
                has.insert(i);
                break;
            }
        }
    }
    return answer;
}