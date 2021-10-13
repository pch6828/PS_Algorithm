class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string temp;
        path.push_back('/');
        for(char c : path){
            if(c == '/'){
                if(temp=="." || temp.empty()){
                    //Do nothing
                }else if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }else{
                    st.push(temp);
                }
                temp.clear();
            }else{
                temp.push_back(c);
            }
        }
        
        string answer;
        while(!st.empty()){
            answer = st.top() + "/" + answer;
            st.pop();
        }
        answer = "/"+answer;
        if(answer != "/"){
            answer.pop_back();
        }
        return answer;
    }
};