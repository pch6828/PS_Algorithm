#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string ans(n, 'O');
    stack<int>deleted;
    priority_queue<int>front;
    priority_queue<int, vector<int>, greater<int>>rear;
    
    for(int i = 0; i < k; i++){
        front.push(i);
    }
    for(int i = k; i < n; i++){
        rear.push(i);
    }
    
    for(string& str : cmd){
        char c = str[0];
        int t = 0;
        if(c=='U'){
            t = stoi(str.substr(2));
            while(t--){
                rear.push(front.top());
                front.pop();
            }
        }else if(c=='D'){
            t = stoi(str.substr(2));
            while(t--){
                front.push(rear.top());
                rear.pop();
            }
        }else if(c=='C'){
            ans[rear.top()]='X';
            deleted.push(rear.top());
            rear.pop();
            if(rear.empty()){
                rear.push(front.top());
                front.pop();
            }
        }else if(c=='Z'){
            ans[deleted.top()]='O';
            if(deleted.top() > rear.top()){
                rear.push(deleted.top());
            }else{
                front.push(deleted.top());
            }
            deleted.pop();
        }
    }
    return ans;
}