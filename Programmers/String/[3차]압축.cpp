#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TrieNode{
private:
    int value;
    TrieNode* child[26];
public:
   TrieNode(int value){
       this->value = value;
       for(int i = 0; i < 26; i++){
           child[i] = nullptr;
        }
    }
    friend class Trie;
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode(0);
        for(int i = 0; i < 26; i++){
            root->child[i] = new TrieNode(i+1);
        }
    }
    int matchAndGetValue(string& str, int& idx){
        TrieNode* it = root;
        int value = 0;
        while(it->child[str[idx]-'A']){
            it = it->child[str[idx]-'A'];
            value = it->value;
            idx++;
            if(idx == str.size()){
                break;
            }
        }
        return value;
    }
    void insertNewSubstr(string& str, int start, int end, int value){
        TrieNode* it = root;
        for(int i = start; i < end; i++){
            it = it->child[str[i]-'A'];
        }
        it->child[str[end]-'A'] = new TrieNode(value);
    }
};

vector<int> solution(string msg) {
    vector<int> ans;
    Trie trie;
    
    int start = 0;
    int end = 0;
    int nxtValue = 27;
    while(end < msg.size()){
        start = end;
        int value = trie.matchAndGetValue(msg, end);
        ans.push_back(value);
        if(end < msg.size()){
            trie.insertNewSubstr(msg, start, end, nxtValue++);
        }
    }
    return ans;
}