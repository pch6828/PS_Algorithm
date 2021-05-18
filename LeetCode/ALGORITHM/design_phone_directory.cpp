class PhoneDirectory {
private:
    int len;
    vector<bool>slot;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->len = maxNumbers;
        this->slot = vector<bool>(this->len, true);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for(int i = 0; i < this->len; i++){
            if(slot[i]){
                slot[i] = false;
                return i;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return slot[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        slot[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */