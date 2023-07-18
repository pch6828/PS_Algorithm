class LRUCache {
private:
    int capacity;
    list<int>keys;
    unordered_map<int, pair<list<int>::iterator, int>>cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        int val;
        if(!cache.count(key))
            return -1;

        pair<list<int>::iterator, int>& cache_entry = cache[key];
        val = cache_entry.second;
        keys.erase(cache_entry.first);
        keys.push_front(key);
        cache_entry.first = keys.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            pair<list<int>::iterator, int>& cache_entry = cache[key];
            keys.erase(cache_entry.first);
            keys.push_front(key);
            cache_entry.first = keys.begin();
            cache_entry.second = value;
            return;
        }
        else if(keys.size() == capacity){
            int victim = keys.back();
            keys.pop_back();
            cache.erase(victim);
        }

        keys.push_front(key);
        cache[key] = {keys.begin(), value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */