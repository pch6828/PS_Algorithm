#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string ans = "";
    for(char c : new_id){
        if(c=='-' || c=='_'
           || ('0'<=c&&c<='9')
           || ('a'<=c&&c<='z')){
            ans.push_back(c);
        }else if('A'<=c&&c<='Z'){
            ans.push_back(c+32);
        }else if(c=='.'){
            if(!ans.empty() && ans.back()!='.'){
                ans.push_back(c);
            }
        }
    }
    while(!ans.empty()&&ans.back()=='.'){
        ans.pop_back();
    }
    if(ans.empty()){
        ans.push_back('a');
    }
    if(ans.size()>=16){
        ans = ans.substr(0, 15);
        while(!ans.empty()&&ans.back()=='.'){
            ans.pop_back();
        }
    }
    while(ans.size()<=2){
        ans.push_back(ans.back());
    }
    return ans;
}