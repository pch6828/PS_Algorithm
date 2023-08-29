class RLEIterator {
private:
    vector<int>* data;
    int cur_cnt_cell;
public:
    RLEIterator(vector<int>& encoding) {
        this->data = &encoding;
        cur_cnt_cell = 0;
    }
    
    int next(int n) {
        int val = -1;
        for(;cur_cnt_cell < data->size(); cur_cnt_cell+=2){
            if(n <= (*data)[cur_cnt_cell]){
                (*data)[cur_cnt_cell] -= n;
                val = (*data)[cur_cnt_cell+1];
                break;
            }
            else{
                n -= (*data)[cur_cnt_cell];
                (*data)[cur_cnt_cell] = 0;
            }
        }

        return val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */