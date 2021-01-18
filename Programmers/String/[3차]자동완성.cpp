#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
public:
    Trie* child[26];
    int cnt;
    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        cnt = 0;
    }
    void insert(string& str, int idx = 0) {
        cnt++;
        if (idx == str.size()) {
            return;
        }
        if (!child[str[idx] - 'a']) {
            child[str[idx] - 'a'] = new Trie();
        }
        child[str[idx] - 'a']->insert(str, idx + 1);
    }
    int find(string& str, int idx = 0) {
        if (cnt==1) {
            return idx;
        }else if(idx==str.size()){
            return str.size();
        }
        if (child[str[idx] - 'a']) {
            return child[str[idx] - 'a']->find(str, idx + 1);
        }
        else {
            return 0;
        }
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for(string word : words){
        trie.insert(word);
    }
    for(string word : words){
        answer+=trie.find(word);
    }
    
    return answer;
}