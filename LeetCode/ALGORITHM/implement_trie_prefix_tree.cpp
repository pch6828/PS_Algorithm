class Trie {
private:
    bool end_point;
    map<char, Trie*>child;
public:
    /** Initialize your data structure here. */
    Trie() {
        end_point = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int idx = 0) {
        if(idx == word.size()){
            end_point = true;
            return;
        }
        if(!child.count(word[idx])){
            child[word[idx]] = new Trie();
        }
        child[word[idx]]->insert(word, idx+1);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word, int idx = 0) {
        if(idx == word.size()){
            return end_point;
        }
        if(!child.count(word[idx])){
            return false;
        }
        return child[word[idx]]->search(word, idx+1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix, int idx = 0) {
        if(idx == prefix.size()){
            return true;
        }
        if(!child.count(prefix[idx])){
            return false;
        }
        return child[prefix[idx]]->startsWith(prefix, idx+1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */