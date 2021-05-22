class Solution {
private:
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        
        for(int bill : bills){
            int change = bill - 5;
            
            while(change >= 20&&twenty){
                twenty--;
                change-=20;
            }
            while(change >= 10&&ten){
                ten--;
                change-=10;
            }
            while(change >= 5 && five){
                five--;
                change-=5;
            }
            if(change){
                return false;
            }
            
            if(bill==5){
                five++;
            }else if(bill==10){
                ten++;
            }else if(bill==20){
                twenty++;
            }
        }
        return true;
    }
};