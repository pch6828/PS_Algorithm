class Solution {
public:
    string reverseVowels(string s) {
        stack<char>st;
        
        for(auto c : s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                st.push(c);
            }
        }
        for(auto& c : s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                c = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};