class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = INT_MAX;
        int ans;
        deque<int>postfix;
        deque<int>prefix;

        postfix.push_back(0);

        for(int i = 0; i < customers.size(); i++){
            int pre = customers[i] == 'N';
            int post = customers[customers.size()-1-i] == 'Y';

            if(prefix.empty())
                prefix.push_back(pre);
            else
                prefix.push_back(pre+prefix.back());
            
            postfix.push_front(postfix.front()+post);
        }

        for(int i = 0; i <= customers.size(); i++){
            if(!i){
                if(penalty > postfix[i]){
                    penalty = postfix[i];
                    ans = i;
                }
            }else{
                if(penalty > postfix[i]+prefix[i-1]){
                    penalty = postfix[i]+prefix[i-1];
                    ans = i;
                }
            }

        }

        return ans;
    }
};