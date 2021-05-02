class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int carry = 0, i = 0;
        while(k||carry){
            if(i==num.size()){
                num.push_back(0);
            }
            num[i]+=carry+k%10;
            k/=10;
            carry = num[i]/10;
            num[i] %= 10;
            i++;
        }
        reverse(num.begin(), num.end());
        return num;
    }
    vector<int> plusOne(vector<int>& digits) {
        return addToArrayForm(digits, 1);
    }
};