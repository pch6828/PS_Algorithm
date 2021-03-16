#include <string>
#include <vector>
#include <list>

using namespace std;

bool is_hit(list<string>&cache, string& target){
    bool result = false;
    for(string str : cache){
        if(target==str){
            result = true;
        }
    }
    if(result){
        cache.remove(target);
    }
    return result;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0){
        return 5*cities.size();
    }
    list<string>cache;
    for(string str:cities){
        for(char& c : str){
            c |= 32;
        }
        if(is_hit(cache, str)){
            answer++;
        }else{
            answer+=5;
        }
        cache.push_front(str);
        if(cache.size()>cacheSize){
            cache.pop_back();
        }
    }
    
    return answer;
}