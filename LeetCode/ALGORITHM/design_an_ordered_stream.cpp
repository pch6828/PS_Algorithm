class OrderedStream {
private:
    int target;
    map<int, string>db;
public:
    OrderedStream(int n) {
        target = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string>result;
        db[idKey] = value;
        
        while(db.count(target)){
            result.push_back(db[target++]);
        }
        
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */