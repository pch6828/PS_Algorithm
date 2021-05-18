class Solution {
public:
    string reformatDate(string date) {
        string answer, temp, month, year;
        string month_map[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int day;
        istringstream sin(date);
        
        sin>>day>>temp>>month>>year;
        
        answer = year;
        answer.push_back('-');
        for(int i = 0; i < 12; i++){
            if(month==month_map[i]){
                if(i < 9){
                    answer.push_back('0');
                }
                answer += to_string(i+1);
                break;
            }
        }
        
        answer.push_back('-');
        if(day < 10){
            answer.push_back('0');
        }
        answer += to_string(day);
        
        return answer;
    }
};