class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int answer = num;
        for(int i = 0; i < str.size(); i++){
            char temp = str[i];
            str[i] = '6';
            answer = max(answer, stoi(str));
            str[i] = '9';
            answer = max(answer, stoi(str));
            str[i] = temp;
        }
        return answer;
    }
};