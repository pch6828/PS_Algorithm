#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int>id_map;
    vector<int>adj[1000];
    int cnt[1000] = {0, };
    for(int i = 0; i < id_list.size(); i++){
        id_map[id_list[i]] = i;
    }
    sort(report.begin(), report.end());
    auto it = unique(report.begin(), report.end());
    report.resize(distance(report.begin(), it));
    for(string& str : report){
        for(int i = 0; i < str.size(); i++){
            if(str[i]==' '){
                int a = id_map[str.substr(0, i)];
                int b = id_map[str.substr(i+1)];
                adj[b].push_back(a);
                cnt[b]++;
                break;
            }
        }
    }
    
    for(int i = 0; i < id_list.size(); i++){
        if(cnt[i]>=k){
            for(int a : adj[i]){
                answer[a]++;
            }
        }
    }
    
    return answer;
}