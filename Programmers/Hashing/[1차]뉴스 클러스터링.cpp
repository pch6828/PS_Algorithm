#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int>dict;
    int U = 0, I = 0, n = str1.size();
    for(int i = 0; i < n-1; i++){
        string temp;
        bool flag = true;
        temp.push_back(str1[i]);
        temp.push_back(str1[i+1]);
        if(temp[0]<='z'&&temp[0]>='a'){
            temp[0]-=32;
        }else if(temp[0]<='Z'&&temp[0]>='A'){
            //no operation
        }else{
            flag = false;
        }
        if(temp[1]<='z'&&temp[1]>='a'){
            temp[1]-=32;
        }else if(temp[1]<='Z'&&temp[1]>='A'){
            //no operation
        }else{
            flag = false;
        }
        if(flag){
            dict[temp]++;
        }
    }
    n = str2.size();
    for(int i = 0; i < n-1; i++){
        string temp;
        bool flag = true;
        temp.push_back(str2[i]);
        temp.push_back(str2[i+1]);
        if(temp[0]<='z'&&temp[0]>='a'){
            temp[0]-=32;
        }else if(temp[0]<='Z'&&temp[0]>='A'){
            //no operation
        }else{
            flag = false;
        }
        if(temp[1]<='z'&&temp[1]>='a'){
            temp[1]-=32;
        }else if(temp[1]<='Z'&&temp[1]>='A'){
            //no operation
        }else{
            flag = false;
        }
        if(flag){
            if(dict[temp]){
                dict[temp]--;
                I++;
                U++;
            }else{
                U++;
            }
        }
    }
    for(auto p : dict){
        U+=p.second;
    }
    if(U==0)return 65536;
    return I*65536/U;
}