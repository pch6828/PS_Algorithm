#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int n = begin.size();
    set<string>dict(words.begin(), words.end());
    map<string, int>cnt;
    queue<string>bfs;
    bfs.push(begin);
    while(!bfs.empty()){
        string now = bfs.front();
        bfs.pop();
        if(now==target){
            return cnt[now];
        }
        for(int i = 0; i < n; i++){
            for(char c = 'a'; c <= 'z'; c++){
                string tmp = now;
                tmp[i] = c;
                if(dict.count(tmp)&&!cnt[tmp]){
                    cnt[tmp] = cnt[now]+1;
                    bfs.push(tmp);
                }
            }
        }
    }
    
    return 0;
}