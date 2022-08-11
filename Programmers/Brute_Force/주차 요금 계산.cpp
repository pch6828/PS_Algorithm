#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int>in_time;
    map<int, int>parking_fee;
    
    for(string& record : records){
        int h = (record[0]-'0')*10+(record[1]-'0');
        int m = (record[3]-'0')*10+(record[4]-'0');
        int car_num = (record[6]-'0')*1000+(record[7]-'0')*100+(record[8]-'0')*10+(record[9]-'0');
        bool is_in = record[11]=='I';
        
        if(is_in){
            in_time[car_num] = h*60+m;
        }else{
            int time_in = in_time[car_num];
            int time_out = h*60+m;
            
            in_time[car_num] = -1;
            
            parking_fee[car_num]+=(time_out-time_in);
        }
    }
    
    for(auto& p : in_time){
        if(p.second != -1){
            parking_fee[p.first]+=(23*60+59-p.second);
        }
        if(parking_fee[p.first] <= fees[0]){
            answer.push_back(fees[1]);
        }else{
            answer.push_back(fees[1]+((parking_fee[p.first]-fees[0])/fees[2]+!!((parking_fee[p.first]-fees[0])%fees[2]))*fees[3]);
        }
    }
    return answer;
}