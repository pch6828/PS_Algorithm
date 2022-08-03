class MyCalendar {
private:
    map<int, int>schedules;
public:
    MyCalendar() {
        //Do Nothing;
    }
    
    bool book(int start, int end) {
        for(auto p : schedules){
            if(p.first <= start && start < p.second){
                return false;
            }else if(p.first < end && end <= p.second){
                return false;
            }else if(start <= p.first && p.first < end){
                return false;
            }else if(start < p.second && p.second < end){
                return false;
            }else if(p.first >= end){
                break;
            }
        }
        schedules[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */