class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        stack<char>s;

        for(int i = 0; i < colors.size() - 1; i++){
            if(!s.empty() && s.top() == colors[i] && colors[i] == colors[i+1]){
                if(colors[i]=='A')
                    a++;
                else b++;
            }else
                s.push(colors[i]);
        }

        return a > b;
    }
};