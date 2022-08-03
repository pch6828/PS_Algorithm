#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

void parseExpression(vector<long long>&nums, vector<char>&ops, string& expression){
    long long num = 0;
    for(char c : expression){
        if('0'<=c&&c<='9'){
            num*=10;
            num+=c-'0';
        }else{
            ops.push_back(c);
            nums.push_back(num);
            num = 0;
        }
    }
    nums.push_back(num);
}

long long calculate(vector<long long>&nums, vector<char>&ops, string& hierarchy){
    vector<long long>result[3];
    vector<char>tops[3];
    
    result[0].push_back(nums[0]);
    char nowOp = hierarchy[0];
    
    for(int j = 0; j < ops.size(); j++){
        if(ops[j]==nowOp){
            if(nowOp=='+'){
                result[0].back()+=nums[j+1];
            }else if(nowOp=='-'){
                result[0].back()-=nums[j+1];
            }else{
                result[0].back()*=nums[j+1];
            }
        }else{
            tops[0].push_back(ops[j]);
            result[0].push_back(nums[j+1]);
        }
    }
    
    for(int i = 1; i < 3; i++){
        nowOp = hierarchy[i];
        result[i].push_back(result[i-1][0]);
        for(int j = 0; j < tops[i-1].size(); j++){
            if(tops[i-1][j]==nowOp){
                if(nowOp=='+'){
                    result[i].back()+=result[i-1][j+1];
                }else if(nowOp=='-'){
                    result[i].back()-=result[i-1][j+1];
                }else{
                    result[i].back()*=result[i-1][j+1];
                }
            }else{
                tops[i].push_back(tops[i-1][j]);
                result[i].push_back(result[i-1][j+1]);
            }
        }
    }
    return result[2][0];
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long>nums;
    vector<char>ops;
    string hierarchy = "*+-";
    parseExpression(nums, ops, expression);
    
    do{
        answer = max(answer, abs(calculate(nums, ops, hierarchy)));
       
    }while(next_permutation(hierarchy.begin(), hierarchy.end()));
    
    return answer;
}