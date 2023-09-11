class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        bool flag = false;
        flag = purchaseAmount % 10 >= 5;
        purchaseAmount -= purchaseAmount % 10;

        if(flag){
            purchaseAmount+=10;
        }

        return 100 - purchaseAmount;
    }
};