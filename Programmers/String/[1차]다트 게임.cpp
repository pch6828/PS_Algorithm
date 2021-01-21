#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    vector<int>score;
    score.push_back(0);
    
    for(char c:dartResult){
        if('0'<=c&&c<='9'){
            num*=10;
            num+=c-'0';
        }else{
            if(c=='S'){
                score.push_back(num);
            }else if(c=='D'){
                score.push_back(num*num);
            }else if(c=='T'){
                score.push_back(num*num*num);
            }else if(c=='*'){
                score[score.size()-1]*=2;
                score[score.size()-2]*=2;
            }else if(c=='#'){
                score[score.size()-1]*=-1;
            }
            num = 0;
        }
    }
    for(int i : score){
        answer+=i;
    }
    return answer;
}