class Solution {
public:
    int totalMoney(int n) {
        int full_week = n/7;
        int remain_day = n%7;
        return 28*full_week
            +remain_day*(remain_day+1)/2
            +7*(full_week-1)*full_week/2
            +remain_day*full_week;
    }
};