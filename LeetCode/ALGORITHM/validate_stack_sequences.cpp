class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int idx = 0;

        for(int i : popped){
            while(s.empty() || s.top() != i){
                if (idx == pushed.size())
                    return false;
                s.push(pushed[idx]);
                idx++;
            }
            s.pop();
        }

        return true;
    }
};