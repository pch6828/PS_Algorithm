class RandomizedSet {
private:
    vector<int>v;
    unordered_set<int>s;
    random_device rd;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //Do Nothing;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)){
            return false;
        }
        s.insert(val);
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!s.count(val)){
            return false;
        }
        
        int idx;
        for(idx = 0; idx < v.size(); idx++){
            if(v[idx]==val){
                break;
            }
        }
        swap(v[idx], v.back());
        v.pop_back();
        s.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rd()%v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */