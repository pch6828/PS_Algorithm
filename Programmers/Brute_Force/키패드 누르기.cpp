#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lloc = 10, rloc = 11;
    int dist[12][12] = {{0,4,3,4,3,2,3,2,1,2,1,1},
                        {4,0,1,2,1,2,3,2,3,4,3,5},
                        {3,1,0,1,2,1,2,3,2,3,4,4},
                        {4,2,1,0,3,2,1,4,3,2,5,3},
                        {3,1,2,3,0,1,2,1,2,3,2,4},
                        {2,2,1,2,1,0,1,2,1,2,3,3},
                        {3,3,2,1,2,1,0,3,2,1,4,2},
                        {2,2,3,4,1,2,3,0,1,2,1,3},
                        {1,3,2,3,2,1,2,1,0,1,2,2},
                        {2,4,3,2,3,2,1,2,1,0,3,1},
                        {1,3,4,5,2,3,4,1,2,3,0,2},
                        {1,5,4,3,4,3,2,3,2,1,2,0}};
    for(auto i : numbers){
        if(i==1||i==4||i==7){
            answer.push_back('L');
            lloc = i;
        }else if(i==3||i==6||i==9){
            answer.push_back('R');
            rloc = i;
        }else{
            int ldist = dist[lloc][i];
            int rdist = dist[rloc][i];
            if(ldist>rdist){
                answer.push_back('R');
                rloc = i;
            }else if(ldist<rdist){
                answer.push_back('L');
                lloc = i;
            }else{
                if(hand=="right"){
                    answer.push_back('R');
                    rloc = i;
                }else{
                    answer.push_back('L');
                    lloc = i;
                }
            }
        }
    }
    return answer;
}