bool cmp(const int& a, const int& b){
    int ca = 0, cb = 0;
    int ta = a, tb = b;
    while(ta){
        ca+=ta%2;
        ta/=2;
    }
    while(tb){
        cb+=tb%2;
        tb/=2;
    }
    if(ca==cb){
        return a<b;
    }
    return ca < cb;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};