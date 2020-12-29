#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> Song;

typedef struct{
    bool operator()(Song& a, Song& b){
        if(a.first==b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
}compare;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int>genres_cnt;
    map<string, priority_queue<Song, vector<Song>, compare>>dict;
    vector<pair<int, string>>sorted_genres;
    for(int i = 0; i < genres.size(); i++){
        genres_cnt[genres[i]]+=plays[i];
        dict[genres[i]].push({plays[i], i});
    }
    for(auto p : genres_cnt){
        sorted_genres.push_back({p.second, p.first});
    }
    sort(sorted_genres.begin(),sorted_genres.end(), greater<pair<int, string>>());
    
    for(auto p : sorted_genres){
        int cnt = 2;
        while(cnt&&dict[p.second].size()){
            answer.push_back(dict[p.second].top().second);
            dict[p.second].pop();
            cnt--;
        }
    }
    return answer;
}