#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int now = 0;
    int cnt = 0;
    while(answer.size()<t){
        string str;
        int temp = now;
        do{
            int remainder = temp%n;
            if(remainder<10){
                str.push_back(remainder+'0');
            }else{
                str.push_back(remainder-10+'A');
            }
            temp/=n;
        }while(temp);
        while(str.size()){
            cnt++;
            if(cnt==p){
                answer.push_back(str.back());
            }
            if(cnt==m){
                cnt = 0;
            }
            str.pop_back();
        }
        now++;
    }
    while(answer.size()!=t){
        answer.pop_back();
    }
    return answer;
}