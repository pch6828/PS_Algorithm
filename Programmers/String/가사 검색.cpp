#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Trie {
public:
    Trie* child[26];
    map<int, int>cnt;
    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
    void insert(string& str, int idx = 0) {
        if (idx == str.size()) {
            return;
        }
        cnt[str.size()]++;
        if (!child[str[idx] - 'a']) {
            child[str[idx] - 'a'] = new Trie();
        }
        child[str[idx] - 'a']->insert(str, idx + 1);
    }
    int find(string& str, int idx = 0) {
        if (str[idx] == '?') {
            return cnt[str.size()];
        }
        if (child[str[idx] - 'a']) {
            return child[str[idx] - 'a']->find(str, idx + 1);
        }
        else {
            return 0;
        }
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie forward, backward;
    for(string& str:words){
        forward.insert(str);
        reverse(str.begin(), str.end());
        backward.insert(str);
    }
    for(string& str:queries){
        if(str[0]=='?'){
            reverse(str.begin(), str.end());
            answer.push_back(backward.find(str));
        }else{
            answer.push_back(forward.find(str));
        }
    }
    return answer;
}