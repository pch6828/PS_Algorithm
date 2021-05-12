class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        deque<int>dq;
        for(int i : A){
            if(i%2){
                dq.push_back(i);
            }else{
                dq.push_front(i);
            }
        }
        return vector<int>(dq.begin(), dq.end());
    }
};