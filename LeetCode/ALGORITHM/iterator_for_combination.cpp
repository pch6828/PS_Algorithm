class CombinationIterator {
    string str;
    vector<bool>perm;
    bool has_next;
public:
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        perm.resize(characters.size(), true);
        for(int i = 0; i < combinationLength; i++)
            perm[i] = false;
        has_next = true;
    }
    
    string next() {
        string ans;
        for(int i = 0; i < perm.size(); i++){
            if(!perm[i])
                ans.push_back(str[i]);
        }
        has_next = next_permutation(perm.begin(), perm.end());
        return ans;
    }
    
    bool hasNext() {
        return has_next;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */