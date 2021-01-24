#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int seq = 0, cnt = 0;
    while(s!="1"){
        string temp;
        for(char c : s){
            if(c=='1'){
                temp.push_back(c);
            }else{
                cnt++;
            }
        }
        seq++;
        s.clear();
        int n = temp.size();
        while(n){
            s.push_back(n%2+'0');
            n/=2;
        }
    }
    answer.push_back(seq);
    answer.push_back(cnt);
    return answer;
}